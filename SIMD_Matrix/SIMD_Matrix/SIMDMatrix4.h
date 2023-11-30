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

#include "SIMDMatrix4.ipp"