#pragma once
#include "SIMDFloat4.h"
#include <vector>
#include <algorithm>
#include <xmmintrin.h>
#include <smmintrin.h>

#if defined(_MSC_VER) && !defined(_M_ARM) && !defined(_M_ARM64) && !defined(_M_HYBRID_X86_ARM64) && (!_MANAGED) && (!_M_CEE) && (!defined(_M_IX86_FP) || (_M_IX86_FP > 1)) && !defined(_XM_NO_INTRINSICS_)
#define VECTOR_CALL __vectorcall
#else
#define VECTOR_CALL
#endif

struct SIMDMatrix4
{
	__m128 v[4];

	SIMDMatrix4();
	struct NothingInit {};
	SIMDMatrix4(NothingInit);
	VECTOR_CALL SIMDMatrix4(const SIMDMatrix4& v) = default;
	SIMDMatrix4(float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44);
	SIMDMatrix4(const float(&m)[4][4]);
	VECTOR_CALL SIMDMatrix4(SIMDFloat4 v1, SIMDFloat4 v2, SIMDFloat4 v3, SIMDFloat4 v4);
	VECTOR_CALL SIMDMatrix4(const __m128* v);
	static SIMDMatrix4 Identity();
	SIMDMatrix4 VECTOR_CALL operator+(SIMDMatrix4 m) const;
	SIMDMatrix4 operator+() const;
	SIMDMatrix4& VECTOR_CALL operator+=(SIMDMatrix4 m);
	SIMDMatrix4 VECTOR_CALL operator-(SIMDMatrix4 m) const;
	SIMDMatrix4 operator-() const;
	SIMDMatrix4& VECTOR_CALL operator-=(SIMDMatrix4 m);
	SIMDMatrix4 operator*(float k) const;
	friend SIMDMatrix4 VECTOR_CALL operator*(float k, SIMDMatrix4 m);
	SIMDMatrix4& operator*=(float k);
	SIMDMatrix4 VECTOR_CALL operator *(SIMDMatrix4 m) const;
	SIMDMatrix4& VECTOR_CALL operator*=(SIMDMatrix4 m);
	friend SIMDFloat4 VECTOR_CALL operator*(SIMDFloat4 v, SIMDMatrix4 m);
	friend SIMDFloat4& VECTOR_CALL operator*=(SIMDFloat4 v, SIMDMatrix4 m);
	SIMDMatrix4 operator/(float k) const;
	SIMDMatrix4& operator/=(float k);
	float det() const;
};
std::ostream& VECTOR_CALL operator<<(std::ostream& stream, const SIMDMatrix4& v);

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
inline VECTOR_CALL SIMDMatrix4::SIMDMatrix4(const SIMDFloat4 v1, const SIMDFloat4 v2, const SIMDFloat4 v3, const SIMDFloat4 v4)
{
	v[0] = v1.m;
	v[1] = v2.m;
	v[2] = v3.m;
	v[3] = v4.m;
}

inline VECTOR_CALL SIMDMatrix4::SIMDMatrix4(const __m128* _v)
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

inline SIMDMatrix4 VECTOR_CALL SIMDMatrix4::operator+(const SIMDMatrix4 m) const
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

inline SIMDMatrix4& VECTOR_CALL SIMDMatrix4::operator+=(const SIMDMatrix4 m)
{
	for (int i = 0; i < 4; i++)
	{
		v[i] = _mm_add_ps(v[i], m.v[i]);
	}
	return *this;
}

inline SIMDMatrix4 VECTOR_CALL SIMDMatrix4::operator-(const SIMDMatrix4 m) const
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

inline SIMDMatrix4& VECTOR_CALL SIMDMatrix4::operator-=(const SIMDMatrix4 m)
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

inline SIMDMatrix4 VECTOR_CALL operator*(const float k, const SIMDMatrix4 m)
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

inline SIMDFloat4 VECTOR_CALL operator*(const SIMDFloat4 v, const SIMDMatrix4 m)
{
	__m128 vX = _mm_shuffle_ps(v.m, v.m, _MM_SHUFFLE(0, 0, 0, 0));
	__m128 vY = _mm_shuffle_ps(v.m, v.m, _MM_SHUFFLE(1, 1, 1, 1));
	__m128 vZ = _mm_shuffle_ps(v.m, v.m, _MM_SHUFFLE(2, 2, 2, 2));
	__m128 vW = _mm_shuffle_ps(v.m, v.m, _MM_SHUFFLE(3, 3, 3, 3));

	vX = _mm_mul_ps(vX, m.v[0]);
	vY = _mm_mul_ps(vY, m.v[1]);
	vZ = _mm_mul_ps(vZ, m.v[2]);
	vW = _mm_mul_ps(vW, m.v[3]);

	vX = _mm_add_ps(vX, vZ);
	vY = _mm_add_ps(vY, vW);
	vX = _mm_add_ps(vX, vY);

	return SIMDFloat4(vX);
}

inline SIMDFloat4& VECTOR_CALL operator*=(const SIMDFloat4 v, const SIMDMatrix4 m)
{
	__m128 vX = _mm_shuffle_ps(v.m, v.m, _MM_SHUFFLE(0, 0, 0, 0));
	__m128 vY = _mm_shuffle_ps(v.m, v.m, _MM_SHUFFLE(1, 1, 1, 1));
	__m128 vZ = _mm_shuffle_ps(v.m, v.m, _MM_SHUFFLE(2, 2, 2, 2));
	__m128 vW = _mm_shuffle_ps(v.m, v.m, _MM_SHUFFLE(3, 3, 3, 3));

	vX = _mm_mul_ps(vX, m.v[0]);
	vY = _mm_mul_ps(vY, m.v[1]);
	vZ = _mm_mul_ps(vZ, m.v[2]);
	vW = _mm_mul_ps(vW, m.v[3]);

	vX = _mm_add_ps(vX, vZ);
	vY = _mm_add_ps(vY, vW);
	vX = _mm_add_ps(vX, vY);

	SIMDFloat4 result = vX;
	return result;
}

inline SIMDMatrix4 VECTOR_CALL SIMDMatrix4::operator*(const SIMDMatrix4 m) const
{
	__m128 result[4];

	__m128 lmw = v[0];
	__m128 lmx = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(0, 0, 0, 0));
	__m128 lmy = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(1, 1, 1, 1));
	__m128 lmz = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(2, 2, 2, 2));
	lmw = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(3, 3, 3, 3));

	lmx = _mm_mul_ps(lmx, m.v[0]);
	lmy = _mm_mul_ps(lmy, m.v[1]);
	lmz = _mm_mul_ps(lmz, m.v[2]);
	lmw = _mm_mul_ps(lmw, m.v[3]);

	lmx = _mm_add_ps(lmx, lmz);
	lmy = _mm_add_ps(lmy, lmw);
	lmx = _mm_add_ps(lmx, lmy);

	result[0] = lmx;


	lmw = v[1];
	lmx = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(0, 0, 0, 0));
	lmy = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(1, 1, 1, 1));
	lmz = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(2, 2, 2, 2));
	lmw = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(3, 3, 3, 3));

	lmx = _mm_mul_ps(lmx, m.v[0]);
	lmy = _mm_mul_ps(lmy, m.v[1]);
	lmz = _mm_mul_ps(lmz, m.v[2]);
	lmw = _mm_mul_ps(lmw, m.v[3]);

	lmx = _mm_add_ps(lmx, lmz);
	lmy = _mm_add_ps(lmy, lmw);
	lmx = _mm_add_ps(lmx, lmy);

	result[1] = lmx;


	lmw = v[2];
	lmx = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(0, 0, 0, 0));
	lmy = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(1, 1, 1, 1));
	lmz = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(2, 2, 2, 2));
	lmw = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(3, 3, 3, 3));

	lmx = _mm_mul_ps(lmx, m.v[0]);
	lmy = _mm_mul_ps(lmy, m.v[1]);
	lmz = _mm_mul_ps(lmz, m.v[2]);
	lmw = _mm_mul_ps(lmw, m.v[3]);

	lmx = _mm_add_ps(lmx, lmz);
	lmy = _mm_add_ps(lmy, lmw);
	lmx = _mm_add_ps(lmx, lmy);

	result[2] = lmx;


	lmw = v[3];
	lmx = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(0, 0, 0, 0));
	lmy = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(1, 1, 1, 1));
	lmz = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(2, 2, 2, 2));
	lmw = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(3, 3, 3, 3));

	lmx = _mm_mul_ps(lmx, m.v[0]);
	lmy = _mm_mul_ps(lmy, m.v[1]);
	lmz = _mm_mul_ps(lmz, m.v[2]);
	lmw = _mm_mul_ps(lmw, m.v[3]);

	lmx = _mm_add_ps(lmx, lmz);
	lmy = _mm_add_ps(lmy, lmw);
	lmx = _mm_add_ps(lmx, lmy);

	result[3] = lmx;

	return SIMDMatrix4(result);
}

inline SIMDMatrix4& VECTOR_CALL SIMDMatrix4::operator*=(const SIMDMatrix4 m)
{
	__m128 result[4];

	__m128 lmw = v[0];
	__m128 lmx = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(0, 0, 0, 0));
	__m128 lmy = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(1, 1, 1, 1));
	__m128 lmz = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(2, 2, 2, 2));
	lmw = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(3, 3, 3, 3));

	lmx = _mm_mul_ps(lmx, m.v[0]);
	lmy = _mm_mul_ps(lmy, m.v[1]);
	lmz = _mm_mul_ps(lmz, m.v[2]);
	lmw = _mm_mul_ps(lmw, m.v[3]);

	lmx = _mm_add_ps(lmx, lmz);
	lmy = _mm_add_ps(lmy, lmw);
	lmx = _mm_add_ps(lmx, lmy);

	result[0] = lmx;


	lmw = v[1];
	lmx = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(0, 0, 0, 0));
	lmy = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(1, 1, 1, 1));
	lmz = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(2, 2, 2, 2));
	lmw = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(3, 3, 3, 3));

	lmx = _mm_mul_ps(lmx, m.v[0]);
	lmy = _mm_mul_ps(lmy, m.v[1]);
	lmz = _mm_mul_ps(lmz, m.v[2]);
	lmw = _mm_mul_ps(lmw, m.v[3]);

	lmx = _mm_add_ps(lmx, lmz);
	lmy = _mm_add_ps(lmy, lmw);
	lmx = _mm_add_ps(lmx, lmy);

	result[1] = lmx;


	lmw = v[2];
	lmx = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(0, 0, 0, 0));
	lmy = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(1, 1, 1, 1));
	lmz = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(2, 2, 2, 2));
	lmw = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(3, 3, 3, 3));

	lmx = _mm_mul_ps(lmx, m.v[0]);
	lmy = _mm_mul_ps(lmy, m.v[1]);
	lmz = _mm_mul_ps(lmz, m.v[2]);
	lmw = _mm_mul_ps(lmw, m.v[3]);

	lmx = _mm_add_ps(lmx, lmz);
	lmy = _mm_add_ps(lmy, lmw);
	lmx = _mm_add_ps(lmx, lmy);

	result[2] = lmx;


	lmw = v[3];
	lmx = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(0, 0, 0, 0));
	lmy = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(1, 1, 1, 1));
	lmz = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(2, 2, 2, 2));
	lmw = _mm_shuffle_ps(lmw, lmw, _MM_SHUFFLE(3, 3, 3, 3));

	lmx = _mm_mul_ps(lmx, m.v[0]);
	lmy = _mm_mul_ps(lmy, m.v[1]);
	lmz = _mm_mul_ps(lmz, m.v[2]);
	lmw = _mm_mul_ps(lmw, m.v[3]);

	lmx = _mm_add_ps(lmx, lmz);
	lmy = _mm_add_ps(lmy, lmw);
	lmx = _mm_add_ps(lmx, lmy);

	result[3] = lmx;

	*this = SIMDMatrix4(result);
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
	__m128 v0 = _mm_shuffle_ps(v[2], v[2], _MM_SHUFFLE(0, 0, 0, 1));
	__m128 v1 = _mm_shuffle_ps(v[3], v[3], _MM_SHUFFLE(1, 1, 2, 2));
	__m128 v2 = _mm_shuffle_ps(v[2], v[2], _MM_SHUFFLE(0, 0, 0, 1));
	__m128 v3 = _mm_shuffle_ps(v[3], v[3], _MM_SHUFFLE(2, 3, 3, 3));
	__m128 v4 = _mm_shuffle_ps(v[2], v[2], _MM_SHUFFLE(1, 1, 2, 2));
	__m128 v5 = _mm_shuffle_ps(v[3], v[3], _MM_SHUFFLE(2, 3, 3, 3));

	__m128 p0 = _mm_mul_ps(v0, v1);
	__m128 p1 = _mm_mul_ps(v2, v3);
	__m128 p2 = _mm_mul_ps(v4, v5);

	v0 = _mm_shuffle_ps(v[2], v[2], _MM_SHUFFLE(1, 1, 2, 2));
	v1 = _mm_shuffle_ps(v[3], v[3], _MM_SHUFFLE(0, 0, 0, 1));
	v2 = _mm_shuffle_ps(v[2], v[2], _MM_SHUFFLE(2, 3, 3, 3));
	v3 = _mm_shuffle_ps(v[3], v[3], _MM_SHUFFLE(0, 0, 0, 1));
	v4 = _mm_shuffle_ps(v[2], v[2], _MM_SHUFFLE(2, 3, 3, 3));
	v5 = _mm_shuffle_ps(v[3], v[3], _MM_SHUFFLE(1, 1, 2, 2));

	//p0 = _mm_fnmadd_ps(v0, v1, p0); ‚Æ“¯‹`
	p0 = _mm_sub_ps(p0, _mm_mul_ps(v0, v1));
	p1 = _mm_sub_ps(p1, _mm_mul_ps(v2, v3));
	p2 = _mm_sub_ps(p2, _mm_mul_ps(v4, v5));

	v0 = _mm_shuffle_ps(v[1], v[1], _MM_SHUFFLE(2, 3, 3, 3));
	v1 = _mm_shuffle_ps(v[1], v[1], _MM_SHUFFLE(1, 1, 2, 2));
	v2 = _mm_shuffle_ps(v[1], v[1], _MM_SHUFFLE(0, 0, 0, 1));

	__m128 sign = _mm_set_ps(-1, 1, -1, 1);
	__m128 s = _mm_mul_ps(v[0], sign);
	__m128 r = _mm_mul_ps(p0, v0);

	r = _mm_sub_ps(r, _mm_mul_ps(v1, p1));
	r = _mm_add_ps(r, _mm_mul_ps(v2, p2));

	return _mm_cvtss_f32(_mm_dp_ps(s, r, 0b11111111));
}

inline std::ostream& VECTOR_CALL operator<<(std::ostream& stream, const SIMDMatrix4& m)
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