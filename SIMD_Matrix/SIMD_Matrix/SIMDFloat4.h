#pragma once
#include "SIMDFloat3.h"
#include <iostream>
#include <xmmintrin.h>
#include <smmintrin.h>

#if defined(_MSC_VER) && !defined(_M_ARM) && !defined(_M_ARM64) && !defined(_M_HYBRID_X86_ARM64) && (!_MANAGED) && (!_M_CEE) && (!defined(_M_IX86_FP) || (_M_IX86_FP > 1)) && !defined(_XM_NO_INTRINSICS_)
#define VECTOR_CALL __vectorcall
#else
#define VECTOR_CALL
#endif

struct SIMDFloat4
{
	__m128 m;
	struct NothingInit {};

	SIMDFloat4();
	SIMDFloat4(NothingInit);
	VECTOR_CALL SIMDFloat4(const SIMDFloat4& v) = default;
	SIMDFloat4(float x, float y, float z, float w);
	VECTOR_CALL SIMDFloat4(SIMDFloat3 v, float w);
	SIMDFloat4(const float* e);
	VECTOR_CALL SIMDFloat4(__m128 e);
	SIMDFloat4 VECTOR_CALL operator+(SIMDFloat4 v) const;
	SIMDFloat4& VECTOR_CALL operator+=(SIMDFloat4 v);
	SIMDFloat4 operator+() const;
	SIMDFloat4 VECTOR_CALL operator-(SIMDFloat4 v) const;
	SIMDFloat4& VECTOR_CALL operator-=(SIMDFloat4 v);
	SIMDFloat4 operator-() const;
	SIMDFloat4 operator*(float k) const;
	friend SIMDFloat4 VECTOR_CALL operator*(float k, SIMDFloat4 v);
	SIMDFloat4&  operator*=(float k);
	SIMDFloat4  operator/(float k) const;
	SIMDFloat4&  operator/=(float k);
	bool VECTOR_CALL equal(SIMDFloat4 v, float epsilon = 0.01) const;
	bool isZero() const;

	SIMDFloat4 length() const;
	SIMDFloat4 squareLength() const;
	SIMDFloat4& normalize();
	SIMDFloat4 normalized() const;
	float getX() const;
	float getY() const;
	float getZ() const;
	float getW() const;
	static SIMDFloat4 VECTOR_CALL Dot(SIMDFloat4 v1, SIMDFloat4 v2);
	static SIMDFloat4 VECTOR_CALL Normalize(SIMDFloat4 v);
};
std::ostream& VECTOR_CALL operator<<(std::ostream& stream, SIMDFloat4 v);

#include "SIMDFloat4.ipp"