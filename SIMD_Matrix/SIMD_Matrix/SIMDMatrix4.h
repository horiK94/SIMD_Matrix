#pragma once
#include "SIMDFloat4.h"
#include <vector>
#include <algorithm>

struct SIMDMatrix4
{
	__m128 v[4];

	SIMDMatrix4();
	struct NothingInit {};
	SIMDMatrix4(NothingInit);
	SIMDMatrix4(const SIMDMatrix4& v) = default;
	SIMDMatrix4(float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44);
	SIMDMatrix4(const float(&m)[4][4]);
	SIMDMatrix4(const SIMDFloat4& v1, const SIMDFloat4& v2, const SIMDFloat4& v3, const SIMDFloat4& v4);
	SIMDMatrix4(const __m128* v);
	static SIMDMatrix4 Identity();
	SIMDMatrix4 operator+(const SIMDMatrix4& m) const;
	SIMDMatrix4 operator+() const;
	SIMDMatrix4& operator+=(const SIMDMatrix4& m);
	SIMDMatrix4 operator-(const SIMDMatrix4& m) const;
	SIMDMatrix4 operator-() const;
	SIMDMatrix4& operator-=(const SIMDMatrix4& m);
	SIMDMatrix4 operator*(float k) const;
	friend SIMDMatrix4 operator*(float k, const SIMDMatrix4& m);
	SIMDMatrix4& operator*=(float k);
	SIMDMatrix4 operator *(const SIMDMatrix4& m) const;
	SIMDMatrix4& operator*=(const SIMDMatrix4& m);
	friend SIMDFloat4 operator*(const SIMDFloat4& v, const SIMDMatrix4& m);
	friend SIMDFloat4& operator*=(const SIMDFloat4& v, const SIMDMatrix4& m);
	SIMDMatrix4 operator/(float k) const;
	SIMDMatrix4& operator/=(float k);
	float det() const;
	float storeValue(int _wi, int _hi) const;
};
std::ostream& operator<<(std::ostream& stream, const SIMDMatrix4& v);

inline SIMDMatrix4::SIMDMatrix4()
{
	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_setzero_ps();
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
	v[0] = _mm_set_ps(m03, m02, m01, m00);
	v[1] = _mm_set_ps(m13, m12, m11, m10);
	v[2] = _mm_set_ps(m23, m22, m21, m20);
	v[3] = _mm_set_ps(m33, m32, m31, m30);
}

inline SIMDMatrix4::SIMDMatrix4(const float(&mat)[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_set_ps(mat[i][3], mat[i][2], mat[i][1], mat[i][0]);
	}
}
inline SIMDMatrix4::SIMDMatrix4(const SIMDFloat4& v1, const SIMDFloat4& v2, const SIMDFloat4& v3, const SIMDFloat4& v4)
{
	v[0] = v1.m;
	v[1] = v2.m;
	v[2] = v3.m;
	v[3] = v4.m;
}

inline SIMDMatrix4::SIMDMatrix4(const __m128* _v)
{
	for (int i = 0; i < 4; i++)
	{
		v[i] = _v[i];
	}
}

inline SIMDMatrix4 SIMDMatrix4::Identity()
{
	SIMDMatrix4 m(NothingInit{});
	m.v[0] = _mm_set_ps(0, 0, 0, 1);
	m.v[1] = _mm_set_ps(0, 0, 1, 0);
	m.v[2] = _mm_set_ps(0, 1, 0, 0);
	m.v[3] = _mm_set_ps(1, 0, 0, 0);
	return m;
}

inline SIMDMatrix4 SIMDMatrix4::operator+(const SIMDMatrix4& m) const
{
	__m128 tv[4];

	for (int i = 0; i < 4; i++)
	{
		tv[i] = _mm_add_ps(v[i], m.v[i]);
	}
	return SIMDMatrix4(tv);
}

inline SIMDMatrix4 SIMDMatrix4::operator+() const
{
	return *this;
}

inline SIMDMatrix4& SIMDMatrix4::operator+=(const SIMDMatrix4& m)
{
	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_add_ps(v[i], m.v[i]);
	}
	return *this;
}

inline SIMDMatrix4 SIMDMatrix4::operator-(const SIMDMatrix4& m) const
{
	__m128 tv[4];

	for (int i = 0; i < 4; i++)
	{
		tv[i] = _mm_sub_ps(v[i], m.v[i]);
	}
	return SIMDMatrix4(tv);
}

inline SIMDMatrix4 SIMDMatrix4::operator-() const
{
	__m128 tv[4];

	for (int i = 0; i < 4; i++)
	{
		tv[i] = _mm_mul_ps(v[i], _mm_set1_ps(-1));
	}
	return SIMDMatrix4(tv);
}

inline SIMDMatrix4& SIMDMatrix4::operator-=(const SIMDMatrix4& m)
{
	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_sub_ps(v[i], m.v[i]);
	}
	return *this;
}

inline SIMDMatrix4 SIMDMatrix4::operator*(float k) const
{
	__m128 tv[4];

	for (int i = 0; i < 4; i++)
	{
		tv[i] = _mm_mul_ps(v[i], _mm_set1_ps(k));
	}
	return SIMDMatrix4(tv);
}

inline SIMDMatrix4 operator*(const float k, const SIMDMatrix4& m)
{
	__m128 tv[4];

	for (int i = 0; i < 4; i++)
	{
		tv[i] = _mm_mul_ps(m.v[i], _mm_set1_ps(k));
	}
	return SIMDMatrix4(tv);
}

inline SIMDMatrix4& SIMDMatrix4::operator*=(const float k)
{
	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_mul_ps(v[i], _mm_set1_ps(k));
	}
	return *this;
}

inline SIMDFloat4 operator*(const SIMDFloat4& v, const SIMDMatrix4& m)
{
	__m128 mVert[4];
	for (int i = 0; i < 4; i++)
	{
		mVert[i] = _mm_set_ps(m.storeValue(3, i), m.storeValue(2, i), m.storeValue(1, i), m.storeValue(0, i));
	}

	float num[4];
	for (int i = 0; i < 4; i++)
	{
		__m128 right = mVert[i];

		__m128 mul = _mm_mul_ps(v.m, right);

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
		mVert[i] = _mm_set_ps(m.storeValue(3, i), m.storeValue(2, i), m.storeValue(1, i), m.storeValue(0, i));
	}

	float num[4];
	for (int i = 0; i < 4; i++)
	{
		__m128 right = mVert[i];

		__m128 mul = _mm_mul_ps(v.m, right);

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
		mVert[i] = _mm_set_ps(m.storeValue(3, i), m.storeValue(2, i), m.storeValue(1, i), m.storeValue(0, i));
	}

	float num[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			__m128 left = v[i];
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
		mVert[i] = _mm_set_ps(m.storeValue(3, i), m.storeValue(2, i), m.storeValue(1, i), m.storeValue(0, i));
	}

	float elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			__m128 left = v[i];
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
	__m128 tv[4];

	for (int i = 0; i < 4; i++)
	{
		tv[i] = _mm_div_ps(v[i], _mm_set1_ps(k));
	}
	return SIMDMatrix4(tv);
}

inline SIMDMatrix4& SIMDMatrix4::operator/=(float k)
{
	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_div_ps(v[i], _mm_set1_ps(k));
	}
	return *this;
}

inline float SIMDMatrix4::det() const
{
	return storeValue(0, 0) * storeValue(1, 1) * storeValue(2, 2) * storeValue(3, 3)
		- storeValue(0, 0) * storeValue(1, 1) * storeValue(2, 3) * storeValue(3, 2)
		- storeValue(0, 0) * storeValue(2, 1) * storeValue(1, 2) * storeValue(3, 3)
		+ storeValue(0, 0) * storeValue(2, 1) * storeValue(1, 3) * storeValue(3, 2)
		+ storeValue(0, 0) * storeValue(3, 1) * storeValue(1, 2) * storeValue(2, 3)
		- storeValue(0, 0) * storeValue(3, 1) * storeValue(1, 3) * storeValue(2, 2)
		- storeValue(1, 0) * storeValue(0, 1) * storeValue(2, 2) * storeValue(3, 3)
		+ storeValue(1, 0) * storeValue(0, 1) * storeValue(2, 3) * storeValue(3, 2)
		+ storeValue(1, 0) * storeValue(2, 1) * storeValue(0, 2) * storeValue(3, 3)
		- storeValue(1, 0) * storeValue(2, 1) * storeValue(0, 3) * storeValue(3, 2)
		- storeValue(1, 0) * storeValue(3, 1) * storeValue(0, 2) * storeValue(2, 3)
		+ storeValue(1, 0) * storeValue(3, 1) * storeValue(0, 3) * storeValue(2, 2)
		+ storeValue(2, 0) * storeValue(0, 1) * storeValue(1, 2) * storeValue(3, 3)
		- storeValue(2, 0) * storeValue(0, 1) * storeValue(1, 3) * storeValue(3, 2)
		- storeValue(2, 0) * storeValue(1, 1) * storeValue(0, 2) * storeValue(3, 3)
		+ storeValue(2, 0) * storeValue(1, 1) * storeValue(0, 3) * storeValue(3, 2)
		+ storeValue(2, 0) * storeValue(3, 1) * storeValue(0, 2) * storeValue(1, 3)
		- storeValue(2, 0) * storeValue(3, 1) * storeValue(0, 3) * storeValue(1, 2)
		- storeValue(3, 0) * storeValue(0, 1) * storeValue(1, 2) * storeValue(2, 3)
		+ storeValue(3, 0) * storeValue(0, 1) * storeValue(1, 3) * storeValue(2, 2)
		+ storeValue(3, 0) * storeValue(1, 1) * storeValue(0, 2) * storeValue(2, 3)
		- storeValue(3, 0) * storeValue(1, 1) * storeValue(0, 3) * storeValue(2, 2)
		- storeValue(3, 0) * storeValue(2, 1) * storeValue(0, 2) * storeValue(1, 3)
		+ storeValue(3, 0) * storeValue(2, 1) * storeValue(0, 3) * storeValue(1, 2);
}

inline float SIMDMatrix4::storeValue(int _wi, int _hi) const
{
	float num[4];
	_mm_store_ps(num, v[_wi]);

	return num[_hi];
}

inline std::ostream& operator<<(std::ostream& stream, const SIMDMatrix4& m)
{
	float num[4][4];
	_mm_store_ps(num[0], m.v[0]);
	_mm_store_ps(num[1], m.v[1]);
	_mm_store_ps(num[2], m.v[2]);
	_mm_store_ps(num[3], m.v[3]);

	return stream << "{{" << num[0][0] << ", " << num[0][1] << ", " << num[0][2] << ", " << num[0][3] << "},\n"
		<< " {" << num[1][0] << ", " << num[1][1] << ", " << num[1][2] << ", " << num[1][3] << "},\n"
		<< " {" << num[2][0] << ", " << num[2][1] << ", " << num[2][2] << ", " << num[2][3] << "},\n"
		<< " {" << num[3][0] << ", " << num[3][1] << ", " << num[3][2] << ", " << num[3][3] << "}}";
}