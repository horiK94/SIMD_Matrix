#pragma once
#include "SIMDFloat3.h"
#include <iostream>
#include <xmmintrin.h>
#include <smmintrin.h>

struct SIMDFloat4
{
	__m128 m;
	struct NothingInit {};

	SIMDFloat4();
	SIMDFloat4(NothingInit);
	SIMDFloat4(const SIMDFloat4& v) = default;
	SIMDFloat4(float x, float y, float z, float w);
	SIMDFloat4(SIMDFloat3 v, float w);
	SIMDFloat4(const float* e);
	SIMDFloat4(__m128 e);
	SIMDFloat4 operator+(const SIMDFloat4& v) const;
	SIMDFloat4& operator+=(const SIMDFloat4& v);
	SIMDFloat4 operator+() const;
	SIMDFloat4 operator-(const SIMDFloat4& v) const;
	SIMDFloat4& operator-=(const SIMDFloat4& v);
	SIMDFloat4 operator-() const;
	SIMDFloat4 operator*(float k) const;
	friend SIMDFloat4 operator*(float k, const SIMDFloat4& v);
	SIMDFloat4& operator*=(float k);
	SIMDFloat4 operator/(float k) const;
	SIMDFloat4& operator/=(float k);
	bool equal(const SIMDFloat4& v, float epsilon = 0.01) const;
	bool isZero() const;

	SIMDFloat4 length() const;
	SIMDFloat4 squareLength() const;
	SIMDFloat4& normalize();
	SIMDFloat4 normalized() const;
	float getX() const;
	float getY() const;
	float getZ() const;
	float getW() const;

	float storeValue(int _index) const;
	static SIMDFloat4 Dot(const SIMDFloat4& v1, const SIMDFloat4& v2);
	static SIMDFloat4 Normalize(const SIMDFloat4& v);
};
std::ostream& operator<<(std::ostream& stream, const SIMDFloat4& v);

#include "SIMDFloat4.ipp"
