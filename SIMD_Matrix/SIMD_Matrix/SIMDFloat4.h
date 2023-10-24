#pragma once
#include "SIMDFloat3.h"
#include <iostream>
#include <xmmintrin.h>

struct SIMDFloat4
{
	float e[4];

	float x() const;
	float y() const;
	float z() const;
	float w() const;

	struct NothingInit {};

	SIMDFloat4();
	SIMDFloat4(NothingInit);
	SIMDFloat4(const SIMDFloat4& v) = default;
	SIMDFloat4(float x, float y, float z, float w);
	SIMDFloat4(const SIMDFloat3& v, float w);
	SIMDFloat4(const float e[4]);
	SIMDFloat4 operator+(const SIMDFloat4& v) const;
	SIMDFloat4& operator+=(const SIMDFloat4& v);
	SIMDFloat4 operator+() const;
	SIMDFloat4 operator-(const SIMDFloat4& v) const;
	SIMDFloat4& operator-=(const SIMDFloat4& v);
	SIMDFloat4 operator-() const;
	SIMDFloat4 operator*(const float k) const;
	friend SIMDFloat4 operator*(const float k, const SIMDFloat4& v);
	SIMDFloat4& operator*=(const float k);
	SIMDFloat4 operator/(const float k) const;
	SIMDFloat4& operator/=(const float k);
	bool equal(const SIMDFloat4& v, const float epsilon = 0.01) const;
	bool isZero() const;

	float length() const;
	float squareLength() const;
	SIMDFloat4& normalize();
	static float Dot(const SIMDFloat4& v1, const SIMDFloat4& v2);
	static SIMDFloat4 Normalize(const SIMDFloat4& v);
};
std::ostream& operator<<(std::ostream& stream, const SIMDFloat4& v);


inline float SIMDFloat4::x() const
{
	return e[0];
}

inline float SIMDFloat4::y() const
{
	return e[1];
}

inline float SIMDFloat4::z() const
{
	return e[2];
}

inline float SIMDFloat4::w() const
{
	return e[3];
}

inline SIMDFloat4::SIMDFloat4() : e{ 0, 0, 0, 0 }
{
}

inline SIMDFloat4::SIMDFloat4(NothingInit)
{
}

inline SIMDFloat4::SIMDFloat4(float _x, float _y, float _z, float _w) : e{ _x, _y, _z, _w }
{
}

inline SIMDFloat4::SIMDFloat4(const SIMDFloat3& v, float w) : e{ v.e[0], v.e[1], v.e[2], w }
{
}

inline SIMDFloat4::SIMDFloat4(const float e[4]) : e{ e[0], e[1], e[2], e[3] }
{
}

inline SIMDFloat4 SIMDFloat4::operator+(const SIMDFloat4& v) const
{
	__m128 a = _mm_load_ps(e);
	__m128 b = _mm_load_ps(v.e);
	__m128 add = _mm_add_ps(a, b);

	float num[4];
	_mm_store_ps(num, add);

	return SIMDFloat4(num);
}

inline SIMDFloat4& SIMDFloat4::operator+=(const SIMDFloat4& v)
{
	__m128 a = _mm_load_ps(e);
	__m128 b = _mm_load_ps(v.e);
	__m128 add = _mm_add_ps(a, b);

	float num[4];
	_mm_store_ps(num, add);

	*this = SIMDFloat4(num);
	return *this;
}

inline SIMDFloat4 SIMDFloat4::operator+() const
{
	return SIMDFloat4(e);
}

inline SIMDFloat4 SIMDFloat4::operator-(const SIMDFloat4& v) const
{
	__m128 a = _mm_load_ps(e);
	__m128 b = _mm_load_ps(v.e);
	__m128 sub = _mm_sub_ps(a, b);

	float num[4];
	_mm_store_ps(num, sub);

	return SIMDFloat4(num);
}

inline SIMDFloat4& SIMDFloat4::operator-=(const SIMDFloat4& v)
{
	__m128 a = _mm_load_ps(e);
	__m128 b = _mm_load_ps(v.e);
	__m128 sub = _mm_sub_ps(a, b);

	float num[4];
	_mm_store_ps(num, sub);

	*this = SIMDFloat4(num);
	return *this;
}

inline SIMDFloat4 SIMDFloat4::operator-() const
{
	__m128 oneMinus = _mm_set1_ps(-1);
	__m128 a = _mm_load_ps(e);
	__m128 mul = _mm_mul_ps(a, oneMinus);

	float num[4];
	_mm_store_ps(num, mul);

	return SIMDFloat4(num);
}

inline SIMDFloat4 SIMDFloat4::operator*(const float k) const
{
	__m128 coefficient = _mm_set1_ps(k);
	__m128 a = _mm_load_ps(e);
	__m128 mul = _mm_mul_ps(a, coefficient);

	float num[4];
	_mm_store_ps(num, mul);

	return SIMDFloat4(num);
}

inline SIMDFloat4 operator*(const float k, const SIMDFloat4& v)
{
	__m128 coefficient = _mm_set1_ps(k);
	__m128 a = _mm_load_ps(v.e);
	__m128 mul = _mm_mul_ps(a, coefficient);

	float num[4];
	_mm_store_ps(num, mul);

	return SIMDFloat4(num);
}

inline SIMDFloat4& SIMDFloat4::operator*=(const float k)
{
	__m128 coefficient = _mm_set1_ps(k);
	__m128 a = _mm_load_ps(e);
	__m128 mul = _mm_mul_ps(a, coefficient);

	float num[4];
	_mm_store_ps(num, mul);

	*this = SIMDFloat4(num);
	return *this;
}

inline SIMDFloat4 SIMDFloat4::operator/(const float k) const
{
	__m128 a = _mm_load_ps(e);
	__m128 coefficient = _mm_set1_ps(k);
	__m128 div = _mm_div_ps(a, coefficient);

	float num[4];
	_mm_store_ps(num, div);

	return SIMDFloat4(num);
}

inline SIMDFloat4& SIMDFloat4::operator/=(const float k)
{
	__m128 a = _mm_load_ps(e);
	__m128 coefficient = _mm_set1_ps(k);
	__m128 div = _mm_div_ps(a, coefficient);

	float num[4];
	_mm_store_ps(num, div);

	*this = SIMDFloat4(num);
	return *this;
}

inline bool SIMDFloat4::equal(const SIMDFloat4& v, const float epsilon) const
{
	__m128 a = _mm_load_ps(e);
	__m128 b = _mm_load_ps(v.e);
	__m128 sub = _mm_sub_ps(a, b);
	__m128 abs = _mm_add_ps(sub, sub);

	__m128 epsi = _mm_set1_ps(epsilon * epsilon);
	__m128 isUnder = _mm_cmple_ps(abs, epsi);

	float num[4];
	_mm_store_ps(num, isUnder);
	return num[0] && num[1] && num[2] && num[3];
}

inline bool SIMDFloat4::isZero() const
{
	__m128 a = _mm_load_ps(e);
	__m128 zero = _mm_set1_ps(0);
	__m128 isEqual = _mm_cmpeq_ps(a, zero);

	float num[4];
	_mm_store_ps(num, isEqual);
	return num[0] && num[1] && num[2] && num[3];
}

inline float SIMDFloat4::length() const
{
	return sqrt(squareLength());
}

inline float SIMDFloat4::squareLength() const
{
	__m128 a = _mm_load_ps(e);
	__m128 mul = _mm_mul_ps(a, a);

	__m128 movehlAdd = _mm_add_ps(mul, _mm_movehl_ps(mul, mul));

	__m128 revMoveHl = _mm_shuffle_ps(movehlAdd, movehlAdd, 0b1);
	__m128 sqrtLength = _mm_add_ss(movehlAdd, revMoveHl);

	float num[4];
	_mm_store_ps(num, sqrtLength);
	return num[0];
}

inline SIMDFloat4& SIMDFloat4::normalize()
{
	__m128 a = _mm_load_ps(e);
	__m128 k = _mm_set1_ps(1 / length());

	__m128 mul = _mm_mul_ps(a, k);

	float num[4];
	_mm_store_ps(num, mul);

	*this = SIMDFloat4(num);
	return *this;
}

inline float SIMDFloat4::Dot(const SIMDFloat4& v1, const SIMDFloat4& v2)
{
	__m128 a = _mm_load_ps(v1.e);
	__m128 b = _mm_load_ps(v2.e);
	__m128 mul = _mm_mul_ps(a, b);

	__m128 movehlAdd = _mm_add_ps(mul, _mm_movehl_ps(mul, mul));

	__m128 revMoveHl = _mm_shuffle_ps(movehlAdd, movehlAdd, 0b1);
	__m128 dot = _mm_add_ss(movehlAdd, revMoveHl);

	float num[4];
	_mm_store_ps(num, dot);
	return num[0];
}

inline SIMDFloat4 SIMDFloat4::Normalize(const SIMDFloat4& v)
{
	__m128 a = _mm_load_ps(v.e);
	__m128 k = _mm_set1_ps(1 / v.length());

	__m128 mul = _mm_mul_ps(a, k);

	float num[4];
	_mm_store_ps(num, mul);

	return SIMDFloat4(num);
}

inline std::ostream& operator<<(std::ostream& stream, const SIMDFloat4& v)
{
	return stream << "(" << v.e[0] << ", " << v.e[1] << ", " << v.e[2] << ")";
}