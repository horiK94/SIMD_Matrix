#pragma once
#include <iostream>
#include <xmmintrin.h>
#include <smmintrin.h>

#if defined(_MSC_VER) && !defined(_M_ARM) && !defined(_M_ARM64) && !defined(_M_HYBRID_X86_ARM64) && (!_MANAGED) && (!_M_CEE) && (!defined(_M_IX86_FP) || (_M_IX86_FP > 1)) && !defined(_XM_NO_INTRINSICS_)
#define VECTOR_CALL __vectorcall
#else
#define VECTOR_CALL
#endif

struct SIMDFloat3
{
	__m128 m;
	struct NothingInit {};

	SIMDFloat3();
	SIMDFloat3(NothingInit);
	VECTOR_CALL SIMDFloat3(const SIMDFloat3& v) = default;
	SIMDFloat3(float x, float y, float z);
	SIMDFloat3(const float* e);
	VECTOR_CALL SIMDFloat3(__m128 e);
	SIMDFloat3 VECTOR_CALL operator+(SIMDFloat3 v) const;
	SIMDFloat3& VECTOR_CALL operator+=(SIMDFloat3 v);
	SIMDFloat3 operator+() const;
	SIMDFloat3 VECTOR_CALL operator-(SIMDFloat3 v) const;
	SIMDFloat3& VECTOR_CALL operator-=(SIMDFloat3 v);
	SIMDFloat3 operator-() const;
	SIMDFloat3 operator*(float k) const;
	friend SIMDFloat3 VECTOR_CALL operator*(float k, SIMDFloat3 v);
	SIMDFloat3& operator*=(float k);
	SIMDFloat3 operator/(float k) const;
	SIMDFloat3& operator/=(float k);
	bool VECTOR_CALL equal(SIMDFloat3 v, float epsilon = 0.01) const;
	bool isZero() const;

	SIMDFloat3 length() const;
	SIMDFloat3 squareLength() const;
	SIMDFloat3& normalize();
	SIMDFloat3 normalized() const;
	float getX() const;
	float getY() const;
	float getZ() const;

	static SIMDFloat3 VECTOR_CALL Dot(SIMDFloat3 v1, SIMDFloat3 v2);
	static SIMDFloat3 VECTOR_CALL Cross(SIMDFloat3 v1, SIMDFloat3 v2);
	static SIMDFloat3 VECTOR_CALL Normalize(SIMDFloat3 v);
};
std::ostream& VECTOR_CALL operator<<(std::ostream& stream, SIMDFloat3 v);

#include "SIMDFloat3.ipp"