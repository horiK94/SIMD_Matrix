#pragma once
#include "SIMDFloat4.h"
#include <vector>
#include <algorithm>

struct SIMDMatrix4
{
	float m[4][4];

	SIMDMatrix4();
	struct NothingInit {};
	SIMDMatrix4(NothingInit);
	SIMDMatrix4(const SIMDMatrix4& v) = default;
	SIMDMatrix4(float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44);
	SIMDMatrix4(float m[4][4]);
	SIMDMatrix4(const SIMDFloat4& v1, const SIMDFloat4& v2, const SIMDFloat4& v3, const SIMDFloat4& v4);
	SIMDMatrix4(const __m128 v[4]);
	static SIMDMatrix4 Identity();
	SIMDMatrix4 operator+(const SIMDMatrix4& m) const;
	SIMDMatrix4 operator+() const;
	SIMDMatrix4& operator+=(const SIMDMatrix4& m);
	SIMDMatrix4 operator-(const SIMDMatrix4& m) const;
	SIMDMatrix4 operator-() const;
	SIMDMatrix4& operator-=(const SIMDMatrix4& m);
	SIMDMatrix4 operator*(float k) const;
	friend SIMDMatrix4 operator*(const float k, const SIMDMatrix4& m);
	SIMDMatrix4& operator*=(const float k);
	SIMDMatrix4 operator *(const SIMDMatrix4& m) const;
	SIMDMatrix4& operator*=(const SIMDMatrix4& m);
	friend SIMDFloat4 operator*(const SIMDFloat4& v, const SIMDMatrix4& m);
	friend SIMDFloat4& operator*=(const SIMDFloat4& v, const SIMDMatrix4& m);
	SIMDMatrix4 operator/(float k) const;
	SIMDMatrix4& operator/=(float k);
	float Det() const;
};

inline SIMDMatrix4::SIMDMatrix4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m[i][j] = 0;
		}
	}
}

inline SIMDMatrix4::SIMDMatrix4(NothingInit)
{
}

inline SIMDMatrix4::SIMDMatrix4(
	float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33)
{
	m[0][0] = m00;
	m[0][1] = m01;
	m[0][2] = m02;
	m[0][3] = m03;

	m[1][0] = m10;
	m[1][1] = m11;
	m[1][2] = m12;
	m[1][3] = m13;

	m[2][0] = m20;
	m[2][1] = m21;
	m[2][2] = m22;
	m[2][3] = m23;

	m[3][0] = m30;
	m[3][1] = m31;
	m[3][2] = m32;
	m[3][3] = m33;
}

inline SIMDMatrix4::SIMDMatrix4(float mat[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m[i][j] = mat[i][j];
		}
	}
}

inline SIMDMatrix4::SIMDMatrix4(const SIMDFloat4& v1, const SIMDFloat4& v2, const SIMDFloat4& v3, const SIMDFloat4& v4)
{
	m[0][0] = v1.e[0];
	m[0][1] = v1.e[1];
	m[0][2] = v1.e[2];
	m[0][3] = v1.e[3];

	m[1][0] = v2.e[0];
	m[1][1] = v2.e[1];
	m[1][2] = v2.e[2];
	m[1][3] = v2.e[3];

	m[2][0] = v3.e[0];
	m[2][1] = v3.e[1];
	m[2][2] = v3.e[2];
	m[2][3] = v3.e[3];

	m[3][0] = v4.e[0];
	m[3][1] = v4.e[1];
	m[3][2] = v4.e[2];
	m[3][3] = v4.e[3];
}

inline SIMDMatrix4::SIMDMatrix4(const __m128 v[4])
{
	for (int i = 0; i < 4; i++)
	{
		_mm_store_ps(m[i], v[i]);
	}
}

inline SIMDMatrix4 SIMDMatrix4::Identity()
{
	return SIMDMatrix4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
}

inline SIMDMatrix4 SIMDMatrix4::operator+(const SIMDMatrix4& m) const
{
	__m128 v[4];

	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_load_ps(this->m[i]);
		v[i] = _mm_add_ps(v[i], _mm_load_ps(m.m[i]));
	}
	return SIMDMatrix4(v);
}

inline SIMDMatrix4 SIMDMatrix4::operator+() const
{
	return *this;
}

inline SIMDMatrix4& SIMDMatrix4::operator+=(const SIMDMatrix4& m)
{
	for (int i = 0; i < 4; i++)
	{
		__m128 v = _mm_load_ps(this->m[i]);
		v = _mm_add_ps(v, _mm_load_ps(m.m[i]));

		_mm_store_ps(this->m[i], v);
	}

	return *this;
}

inline SIMDMatrix4 SIMDMatrix4::operator-(const SIMDMatrix4& m) const
{
	__m128 v[4];

	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_load_ps(this->m[i]);
		v[i] = _mm_sub_ps(v[i], _mm_load_ps(m.m[i]));
	}
	return SIMDMatrix4(v);
}

inline SIMDMatrix4 SIMDMatrix4::operator-() const
{
	__m128 v[4];

	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_load_ps(this->m[i]);
		v[i] = _mm_mul_ps(v[i], _mm_set1_ps(-1));
	}
	return SIMDMatrix4(v);
}

inline SIMDMatrix4& SIMDMatrix4::operator-=(const SIMDMatrix4& m)
{
	for (int i = 0; i < 4; i++)
	{
		__m128 v = _mm_load_ps(this->m[i]);
		v = _mm_sub_ps(v, _mm_load_ps(m.m[i]));

		_mm_store_ps(this->m[i], v);
	}

	return *this;
}

inline SIMDMatrix4 SIMDMatrix4::operator*(float k) const
{
	__m128 v[4];

	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_load_ps(this->m[i]);
		v[i] = _mm_mul_ps(v[i], _mm_set1_ps(k));
	}
	return SIMDMatrix4(v);
}

inline SIMDMatrix4 operator*(const float k, const SIMDMatrix4& m)
{
	__m128 v[4];

	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_load_ps(m.m[i]);
		v[i] = _mm_mul_ps(v[i], _mm_set1_ps(k));
	}
	return SIMDMatrix4(v);
}

inline SIMDMatrix4& SIMDMatrix4::operator*=(const float k)
{
	for (int i = 0; i < 4; i++)
	{
		__m128 v = _mm_load_ps(this->m[i]);
		v = _mm_mul_ps(v, _mm_set1_ps(k));

		_mm_store_ps(this->m[i], v);
	}

	return *this;
}

inline SIMDFloat4 operator*(const SIMDFloat4& v, const SIMDMatrix4& m)
{
	__m128 mVert[4];
	for (int i = 0; i < 4; i++)
	{
		mVert[i] = _mm_set_ps(m.m[3][i], m.m[2][i], m.m[1][i], m.m[0][i]);
	}

	float num[4];
	for (int i = 0; i < 4; i++)
	{
		__m128 left = _mm_load_ps(v.e);
		__m128 right = mVert[i];

		__m128 mul = _mm_mul_ps(left, right);

		__m128 movehlAdd = _mm_add_ps(mul, _mm_movehl_ps(mul, mul));

		__m128 revMoveHl = _mm_shuffle_ps(movehlAdd, movehlAdd, 0b1);
		__m128 add = _mm_add_ss(movehlAdd, revMoveHl);

		float tmpNum[4];
		_mm_store_ps(tmpNum, add);
		num[i] = tmpNum[0];
	}

	return SIMDFloat4(num);
}

inline SIMDFloat4& operator*=(const SIMDFloat4& v, const SIMDMatrix4& m)
{
	__m128 mVert[4];
	for (int i = 0; i < 4; i++)
	{
		mVert[i] = _mm_set_ps(m.m[3][i], m.m[2][i], m.m[1][i], m.m[0][i]);
	}

	float num[4];
	for (int i = 0; i < 4; i++)
	{
		__m128 left = _mm_load_ps(v.e);
		__m128 right = mVert[i];

		__m128 mul = _mm_mul_ps(left, right);

		__m128 movehlAdd = _mm_add_ps(mul, _mm_movehl_ps(mul, mul));

		__m128 revMoveHl = _mm_shuffle_ps(movehlAdd, movehlAdd, 0b1);
		__m128 add = _mm_add_ss(movehlAdd, revMoveHl);

		float tmpNum[4];
		_mm_store_ps(tmpNum, add);
		num[i] = tmpNum[0];
	}

	SIMDFloat4 calced(num);
	return calced;
}

inline SIMDMatrix4 SIMDMatrix4::operator*(const SIMDMatrix4& m) const
{
	__m128 mVert[4];
	for (int i = 0; i < 4; i++)
	{
		mVert[i] = _mm_set_ps(m.m[3][i], m.m[2][i], m.m[1][i], m.m[0][i]);
	}

	float num[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			__m128 left = _mm_load_ps(this->m[i]);
			__m128 right = mVert[j];

			__m128 mul = _mm_mul_ps(left, right);

			__m128 movehlAdd = _mm_add_ps(mul, _mm_movehl_ps(mul, mul));

			__m128 revMoveHl = _mm_shuffle_ps(movehlAdd, movehlAdd, 0b1);
			__m128 add = _mm_add_ss(movehlAdd, revMoveHl);

			float tmpNum[4];
			_mm_store_ps(tmpNum, add);
			num[i][j] = tmpNum[0];
		}
	}

	return SIMDMatrix4(num);
}

inline SIMDMatrix4& SIMDMatrix4::operator*=(const SIMDMatrix4& m)
{
	__m128 mVert[4];
	for (int i = 0; i < 4; i++)
	{
		mVert[i] = _mm_set_ps(m.m[3][i], m.m[2][i], m.m[1][i], m.m[0][i]);
	}

	float elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			__m128 left = _mm_load_ps(this->m[i]);
			__m128 right = mVert[j];

			__m128 mul = _mm_mul_ps(left, right);

			__m128 movehlAdd = _mm_add_ps(mul, _mm_movehl_ps(mul, mul));

			__m128 revMoveHl = _mm_shuffle_ps(movehlAdd, movehlAdd, 0b1);
			__m128 add = _mm_add_ss(movehlAdd, revMoveHl);

			float tmpNum[4];
			_mm_store_ps(tmpNum, add);
			elem[i][j] = tmpNum[0];		//ここで値を更新してしまうと計算結果が変わるので一時データに入れる
		}
	}

	*this = SIMDMatrix4(elem);
	return *this;
}

inline SIMDMatrix4 SIMDMatrix4::operator/(float k) const
{
	__m128 v[4];

	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_load_ps(this->m[i]);
		v[i] = _mm_div_ps(v[i], _mm_set1_ps(k));
	}
	return SIMDMatrix4(v);
}

inline SIMDMatrix4& SIMDMatrix4::operator/=(float k)
{
	for (int i = 0; i < 4; i++)
	{
		__m128 v = _mm_load_ps(this->m[i]);
		v = _mm_div_ps(v, _mm_set1_ps(k));

		_mm_store_ps(this->m[i], v);
	}

	return *this;
}

inline float SIMDMatrix4::Det() const
{
	return m[0][0] * m[1][1] * m[2][2] * m[3][3]
		- m[0][0] * m[1][1] * m[2][3] * m[3][2]
		- m[0][0] * m[2][1] * m[1][2] * m[3][3]
		+ m[0][0] * m[2][1] * m[1][3] * m[3][2]
		+ m[0][0] * m[3][1] * m[1][2] * m[2][3]
		- m[0][0] * m[3][1] * m[1][3] * m[2][2]
		- m[1][0] * m[0][1] * m[2][2] * m[3][3]
		+ m[1][0] * m[0][1] * m[2][3] * m[3][2]
		+ m[1][0] * m[2][1] * m[0][2] * m[3][3]
		- m[1][0] * m[2][1] * m[0][3] * m[3][2]
		- m[1][0] * m[3][1] * m[0][2] * m[2][3]
		+ m[1][0] * m[3][1] * m[0][3] * m[2][2]
		+ m[2][0] * m[0][1] * m[1][2] * m[3][3]
		- m[2][0] * m[0][1] * m[1][3] * m[3][2]
		- m[2][0] * m[1][1] * m[0][2] * m[3][3]
		+ m[2][0] * m[1][1] * m[0][3] * m[3][2]
		+ m[2][0] * m[3][1] * m[0][2] * m[1][3]
		- m[2][0] * m[3][1] * m[0][3] * m[1][2]
		- m[3][0] * m[0][1] * m[1][2] * m[2][3]
		+ m[3][0] * m[0][1] * m[1][3] * m[2][2]
		+ m[3][0] * m[1][1] * m[0][2] * m[2][3]
		- m[3][0] * m[1][1] * m[0][3] * m[2][2]
		- m[3][0] * m[2][1] * m[0][2] * m[1][3]
		+ m[3][0] * m[2][1] * m[0][3] * m[1][2];
}