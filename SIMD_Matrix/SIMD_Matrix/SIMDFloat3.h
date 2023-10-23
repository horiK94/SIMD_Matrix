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
	__m128 sub = _mm_sub_ps(a, b);
	__m128 abs = _mm_add_ps(sub, sub);

	__m128 epsi = _mm_set1_ps(epsilon * epsilon);
	__m128 isUnder = _mm_cmple_ps(abs, epsi);

	float num[4];
	_mm_store_ps(num, isUnder);
	return num[0] && num[1] && num[2];
}

inline bool SIMDFloat3::isZero() const
{
	__m128 a = _mm_load_ps(e);
	__m128 zero = _mm_set1_ps(0);
	__m128 isEqual = _mm_cmpeq_ps(a, zero);

	float num[4];
	_mm_store_ps(num, isEqual);
	return num[0] && num[1] && num[2];
}

inline float SIMDFloat3::length() const
{
	return sqrt(squareLength());
}

inline float SIMDFloat3::squareLength() const
{
	__m128 a = _mm_setr_ps(e[0], e[1], e[2], 0);
	__m128 mul = _mm_mul_ps(a, a);

	__m128 movehlAdd = _mm_add_ps(mul, _mm_movehl_ps(mul, mul));

	__m128 revMoveHl = _mm_shuffle_ps(movehlAdd, movehlAdd, 0b1);
	__m128 sqrtLength = _mm_add_ss(movehlAdd, revMoveHl);

	float num[4];
	_mm_store_ps(num, sqrtLength);
	return num[0];
}

inline SIMDFloat3& SIMDFloat3::normalize()
{
	__m128 a = _mm_load_ps(e);
	__m128 k = _mm_set1_ps(1 / length());

	__m128 mul = _mm_mul_ps(a, k);

	float num[4];
	_mm_store_ps(num, mul);

	*this = SIMDFloat3(num);
	return *this;
}

inline float SIMDFloat3::Dot(const SIMDFloat3& v1, const SIMDFloat3& v2)
{
	__m128 a = _mm_setr_ps(v1.e[0], v1.e[1], v1.e[2], 0);
	__m128 b = _mm_setr_ps(v2.e[0], v2.e[1], v2.e[2], 0);
	__m128 mul = _mm_mul_ps(a, b);

	__m128 movehlAdd = _mm_add_ps(mul, _mm_movehl_ps(mul, mul));

	__m128 revMoveHl = _mm_shuffle_ps(movehlAdd, movehlAdd, 0b1);
	__m128 dot = _mm_add_ss(movehlAdd, revMoveHl);

	float num[4];
	_mm_store_ps(num, dot);
	return num[0];
}

inline SIMDFloat3 SIMDFloat3::Cross(const SIMDFloat3& v1, const SIMDFloat3& v2)
{
	__m128 a2a3a1 = _mm_set_ps(0, v1.e[0], v1.e[2], v1.e[1]);
	__m128 b3b1b2 = _mm_set_ps(0, v2.e[1], v2.e[0], v2.e[2]);
	__m128 a3a1a2 = _mm_set_ps(0, v1.e[1], v1.e[0], v1.e[2]);
	__m128 b2b3b1 = _mm_set_ps(0, v2.e[0], v2.e[2], v2.e[1]);

	__m128 leftMulti = _mm_mul_ps(a2a3a1, b3b1b2);
	__m128 rightMulti = _mm_mul_ps(a3a1a2, b2b3b1);

	__m128 cross = _mm_sub_ps(leftMulti, rightMulti);

	float num[4];
	_mm_store_ps(num, cross);

	return SIMDFloat3(num);
}

inline SIMDFloat3 SIMDFloat3::Normalize(const SIMDFloat3& v)
{
	__m128 a = _mm_load_ps(v.e);
	__m128 k = _mm_set1_ps(1 / v.length());

	__m128 mul = _mm_mul_ps(a, k);

	float num[4];
	_mm_store_ps(num, mul);

	return SIMDFloat3(num);
}

inline std::ostream& operator<<(std::ostream& stream, const SIMDFloat3& v)
{
	return stream << "(" << v.e[0] << ", " << v.e[1] << ", " << v.e[2] << ")";
}