#pragma once
#include <iostream>
#include <xmmintrin.h>

struct SIMDFloat3
{
	float e[3];

	float x() const;
	float y() const;
	float z() const;

	struct NothingInit {};

	SIMDFloat3();
	SIMDFloat3(NothingInit);
	SIMDFloat3(const SIMDFloat3& v) = default;
	SIMDFloat3(float x, float y, float z);
	SIMDFloat3(const float e[3]);
	SIMDFloat3 operator+(const SIMDFloat3& v) const;
	SIMDFloat3& operator+=(const SIMDFloat3& v);
	SIMDFloat3 operator+() const;
	SIMDFloat3 operator-(const SIMDFloat3& v) const;
	SIMDFloat3& operator-=(const SIMDFloat3& v);
	SIMDFloat3 operator-() const;
	SIMDFloat3 operator*(const float k) const;
	friend SIMDFloat3 operator*(const float k, const SIMDFloat3& v);
	SIMDFloat3& operator*=(const float k);
	SIMDFloat3 operator/(const float k) const;
	SIMDFloat3& operator/=(const float k);
	bool equal(const SIMDFloat3& v, const float epsilon = 0.01) const;
	bool isZero() const;

	float length() const;
	float squareLength() const;
	SIMDFloat3& normalize();

	static float Dot(const SIMDFloat3& v1, const SIMDFloat3& v2);
	static SIMDFloat3 Cross(const SIMDFloat3& v1, const SIMDFloat3& v2);
	static SIMDFloat3 Normalize(const SIMDFloat3& v);
};
std::ostream& operator<<(std::ostream& stream, const SIMDFloat3& v);

inline float SIMDFloat3::x() const
{
	return e[0];
}

inline float SIMDFloat3::y() const
{
	return e[1];
}

inline float SIMDFloat3::z() const
{
	return e[2];
}

inline SIMDFloat3::SIMDFloat3() : e{ 0, 0, 0 }
{
}

inline SIMDFloat3::SIMDFloat3(NothingInit)
{
}

inline SIMDFloat3::SIMDFloat3(float _x, float _y, float _z) : e{ _x, _y, _z }
{
}

inline SIMDFloat3::SIMDFloat3(const float e[3]) : e{ e[0], e[1], e[2] }
{
}

inline SIMDFloat3 SIMDFloat3::operator+(const SIMDFloat3& v) const
{
	__m128 a = _mm_load_ps(e);
	__m128 b = _mm_load_ps(v.e);
	__m128 add = _mm_add_ps(a, b);

	float num[4];
	_mm_store_ps(num, add);

	return SIMDFloat3(num);
}

inline SIMDFloat3& SIMDFloat3::operator+=(const SIMDFloat3& v)
{
	__m128 a = _mm_load_ps(e);
	__m128 b = _mm_load_ps(v.e);
	__m128 add = _mm_add_ps(a, b);

	float num[4];
	_mm_store_ps(num, add);

	*this = SIMDFloat3(num);
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator+() const
{
	return SIMDFloat3(e);
}

inline SIMDFloat3 SIMDFloat3::operator-(const SIMDFloat3& v) const
{
	__m128 a = _mm_load_ps(e);
	__m128 b = _mm_load_ps(v.e);
	__m128 sub = _mm_sub_ps(a, b);

	float num[4];
	_mm_store_ps(num, sub);

	return SIMDFloat3(num);
}

inline SIMDFloat3& SIMDFloat3::operator-=(const SIMDFloat3& v)
{
	__m128 a = _mm_load_ps(e);
	__m128 b = _mm_load_ps(v.e);
	__m128 sub = _mm_sub_ps(a, b);

	float num[4];
	_mm_store_ps(num, sub);

	*this = SIMDFloat3(num);
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator-() const
{
	__m128 oneMinus = _mm_set1_ps(-1);
	__m128 a = _mm_load_ps(e);
	__m128 mul = _mm_mul_ps(a, oneMinus);

	float num[4];
	_mm_store_ps(num, mul);

	return SIMDFloat3(num);
}

inline SIMDFloat3 SIMDFloat3::operator*(const float k) const
{
	__m128 coefficient = _mm_set1_ps(k);
	__m128 a = _mm_load_ps(e);
	__m128 mul = _mm_mul_ps(a, coefficient);

	float num[4];
	_mm_store_ps(num, mul);

	return SIMDFloat3(num);
}

inline SIMDFloat3 operator*(const float k, const SIMDFloat3& v)
{
	__m128 coefficient = _mm_set1_ps(k);
	__m128 a = _mm_load_ps(v.e);
	__m128 mul = _mm_mul_ps(a, coefficient);

	float num[4];
	_mm_store_ps(num, mul);

	return SIMDFloat3(num);
}

inline SIMDFloat3& SIMDFloat3::operator*=(const float k)
{
	__m128 coefficient = _mm_set1_ps(k);
	__m128 a = _mm_load_ps(e);
	__m128 mul = _mm_mul_ps(a, coefficient);

	float num[4];
	_mm_store_ps(num, mul);

	*this = SIMDFloat3(num);
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator/(const float k) const
{
	__m128 a = _mm_load_ps(e);
	__m128 coefficient = _mm_set1_ps(k);
	__m128 div = _mm_div_ps(a, coefficient);

	float num[4];
	_mm_store_ps(num, div);

	return SIMDFloat3(num);
}

inline SIMDFloat3& SIMDFloat3::operator/=(const float k)
{
	__m128 a = _mm_load_ps(e);
	__m128 coefficient = _mm_set1_ps(k);
	__m128 div = _mm_div_ps(a, coefficient);

	float num[4];
	_mm_store_ps(num, div);

	*this = SIMDFloat3(num);
	return *this;
}

inline bool SIMDFloat3::equal(const SIMDFloat3& v, const float epsilon) const
{
	__m128 a = _mm_load_ps(e);
	__m128 b = _mm_load_ps(v.e);
	__m128 abs = _mm_add_ps(a, b);

	__m128 epsi = _mm_set1_ps(epsilon);
	__m128 isUnder = _mm_cmple_ps(abs, epsi);

	float num[4];
	_mm_store_ps(num, isUnder);
	return num[0] + num[1] + num[2] == 0;
}

inline bool SIMDFloat3::isZero() const
{
	__m128 a = _mm_load_ps(e);
	__m128 zero = _mm_set1_ps(0);
	__m128 isEqual = _mm_cmpeq_ps(a, zero);

	float num[4];
	_mm_store_ps(num, isEqual);
	return num[0] + num[1] + num[2] == 0;
}

inline float SIMDFloat3::length() const
{
	return 0.0f;
}

inline float SIMDFloat3::squareLength() const
{
	return 0.0f;
}

inline SIMDFloat3& SIMDFloat3::normalize()
{
	return *this;
}

inline float SIMDFloat3::Dot(const SIMDFloat3& v1, const SIMDFloat3& v2)
{
	return 0.0f;
}

inline SIMDFloat3 SIMDFloat3::Cross(const SIMDFloat3& v1, const SIMDFloat3& v2)
{
	return SIMDFloat3();
}

inline SIMDFloat3 SIMDFloat3::Normalize(const SIMDFloat3& v)
{
	return SIMDFloat3();
}

inline std::ostream& operator<<(std::ostream& stream, const SIMDFloat3& v)
{
	return stream << "(" << v.e[0] << ", " << v.e[1] << ", " << v.e[2] << ")";
}