#pragma once
#include <iostream>
#include <xmmintrin.h>
#include <smmintrin.h>

struct SIMDFloat3
{
	__m128 m;
	struct NothingInit {};

	SIMDFloat3();
	SIMDFloat3(NothingInit);
	SIMDFloat3(const SIMDFloat3& v) = default;
	SIMDFloat3(float x, float y, float z);
	SIMDFloat3(const float* e);
	SIMDFloat3(const __m128 e);
	SIMDFloat3 operator+(const SIMDFloat3& v) const;
	SIMDFloat3& operator+=(const SIMDFloat3& v);
	SIMDFloat3 operator+() const;
	SIMDFloat3 operator-(const SIMDFloat3& v) const;
	SIMDFloat3& operator-=(const SIMDFloat3& v);
	SIMDFloat3 operator-() const;
	SIMDFloat3 operator*(float k) const;
	friend SIMDFloat3 operator*(float k, const SIMDFloat3& v);
	SIMDFloat3& operator*=(float k);
	SIMDFloat3 operator/(float k) const;
	SIMDFloat3& operator/=(float k);
	bool equal(const SIMDFloat3& v, float epsilon = 0.01) const;
	bool isZero() const;

	SIMDFloat3 length() const;
	SIMDFloat3 squareLength() const;
	SIMDFloat3& normalize();
	SIMDFloat3 normalized() const;
	float storeValue(int _index) const;

	static SIMDFloat3 Dot(const SIMDFloat3& v1, const SIMDFloat3& v2);
	static SIMDFloat3 Cross(const SIMDFloat3& v1, const SIMDFloat3& v2);
	static SIMDFloat3 Normalize(const SIMDFloat3& v);
};
std::ostream& operator<<(std::ostream& stream, const SIMDFloat3& v);

inline SIMDFloat3::SIMDFloat3() : m(_mm_setzero_ps())
{
}

inline SIMDFloat3::SIMDFloat3(NothingInit)
{
}

inline SIMDFloat3::SIMDFloat3(float _x, float _y, float _z) : m(_mm_set_ps(0, _z, _y, _x))
{
}

inline SIMDFloat3::SIMDFloat3(const float* e) : m(_mm_loadu_ps(e))
{
}

inline SIMDFloat3::SIMDFloat3(const __m128 e) : m(e)
{
}

inline SIMDFloat3 SIMDFloat3::operator+(const SIMDFloat3& v) const
{
	return SIMDFloat3(_mm_add_ps(m, v.m));
}

inline SIMDFloat3& SIMDFloat3::operator+=(const SIMDFloat3& v)
{
	*this = SIMDFloat3(_mm_add_ps(m, v.m)); ;
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator+() const
{
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator-(const SIMDFloat3& v) const
{
	return SIMDFloat3(_mm_sub_ps(m, v.m));
}

inline SIMDFloat3& SIMDFloat3::operator-=(const SIMDFloat3& v)
{
	*this = SIMDFloat3(_mm_sub_ps(m, v.m));
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator-() const
{
	return SIMDFloat3(_mm_mul_ps(m, _mm_set1_ps(-1)));
}

inline SIMDFloat3 SIMDFloat3::operator*(const float k) const
{
	return SIMDFloat3(_mm_mul_ps(m, _mm_set1_ps(k)));
}

inline SIMDFloat3 operator*(const float k, const SIMDFloat3& v)
{
	return SIMDFloat3(_mm_mul_ps(v.m, _mm_set1_ps(k)));
}

inline SIMDFloat3& SIMDFloat3::operator*=(const float k)
{
	*this = SIMDFloat3(_mm_mul_ps(m, _mm_set1_ps(k)));
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator/(const float k) const
{
	return SIMDFloat3(_mm_div_ps(m, _mm_set1_ps(k)));
}

inline SIMDFloat3& SIMDFloat3::operator/=(const float k)
{
	*this = SIMDFloat3(_mm_div_ps(m, _mm_set1_ps(k)));
	return *this;
}

inline bool SIMDFloat3::equal(const SIMDFloat3& v, const float epsilon) const
{
	__m128 sub = _mm_sub_ps(m, v.m);

	__m128 abs = _mm_mul_ps(sub, sub);
	__m128 epsi = _mm_set1_ps(epsilon * epsilon);

	__m128 isUnder = _mm_cmple_ps(abs, epsi);
	return (_mm_movemask_ps(isUnder) & 0b0111) == 0b0111;
}

inline bool SIMDFloat3::isZero() const
{
	__m128 isEqual = _mm_cmpeq_ps(m, _mm_set1_ps(0));
	return (_mm_movemask_ps(isEqual) & 0b0111) == 0b0111;
}

inline SIMDFloat3 SIMDFloat3::length() const
{
	__m128 mul = _mm_dp_ps(m, m, 0b00111111);
	return _mm_sqrt_ps(mul);
}

inline SIMDFloat3 SIMDFloat3::squareLength() const
{
	return _mm_dp_ps(m, m, 0b00111111);
}

inline SIMDFloat3& SIMDFloat3::normalize()
{
	*this = SIMDFloat3(_mm_div_ps(m, length().m));
	return *this;
}

inline SIMDFloat3 SIMDFloat3::normalized() const
{
	return SIMDFloat3(_mm_div_ps(m, length().m));
}

inline float SIMDFloat3::storeValue(int _index) const
{
	float num[4];
	_mm_store_ps(num, m);

	return num[_index];
}

inline SIMDFloat3 SIMDFloat3::Dot(const SIMDFloat3& v1, const SIMDFloat3& v2)
{
	return SIMDFloat3(_mm_dp_ps(v1.m, v2.m, 0b00111111));
}


inline SIMDFloat3 SIMDFloat3::Cross(const SIMDFloat3& v1, const SIMDFloat3& v2)
{
	float n1[4] = { v1.storeValue(0),  v1.storeValue(1),  v1.storeValue(2) };
	float n2[4] = { v2.storeValue(0),  v2.storeValue(1),  v2.storeValue(2) };

	__m128 a2a3a1 = _mm_set_ps(0, n1[0], n1[2], n1[1]);
	__m128 b3b1b2 = _mm_set_ps(0, n2[1], n2[0], n2[2]);
	__m128 a3a1a2 = _mm_set_ps(0, n1[1], n1[0], n1[2]);
	__m128 b2b3b1 = _mm_set_ps(0, n2[0], n2[2], n2[1]);

	__m128 leftMulti = _mm_mul_ps(a2a3a1, b3b1b2);
	__m128 rightMulti = _mm_mul_ps(a3a1a2, b2b3b1);

	__m128 cross = _mm_sub_ps(leftMulti, rightMulti);
	return SIMDFloat3(cross);
}

inline SIMDFloat3 SIMDFloat3::Normalize(const SIMDFloat3& v)
{
	return SIMDFloat3(_mm_div_ps(v.m, v.length().m));
}

inline std::ostream& operator<<(std::ostream& stream, const SIMDFloat3& v)
{
	float num[4];
	_mm_store_ps(num, v.m);

	return stream << "(" << num[0] << ", " << num[1] << ", " << num[2] << ")";
}