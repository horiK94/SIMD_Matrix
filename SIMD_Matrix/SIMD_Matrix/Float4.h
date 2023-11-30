#pragma once
#include "Float3.h"
#include <iostream>

struct Float4
{
	float x;
	float y;
	float z;
	float w;

	struct NothingInit {};

	Float4();
	Float4(NothingInit);
	Float4(const Float4& v) = default;
	Float4(float x, float y, float z, float w);
	Float4(const Float3& v, float w);
	Float4(const float e[4]);
	Float4 operator+(const Float4& v) const;
	Float4& operator+=(const Float4& v);
	Float4 operator+() const;
	Float4 operator-(const Float4& v) const;
	Float4& operator-=(const Float4& v);
	Float4 operator-() const;
	Float4 operator*(const float k);
	friend Float4 operator*(const float k, const Float4& v);
	Float4& operator*=(const float k);
	Float4 operator/(const float k) const;
	Float4& operator/=(const float k);
	bool equal(const Float4& v, const float epsilon = 0.01) const;
	bool isZero() const;

	float length() const;
	float squareLength() const;
	Float4& normalize();
	static float Dot(const Float4& v1, const Float4& v2);
	static Float4 Normalize(const Float4& v);
};
std::ostream& operator<<(std::ostream& stream, const Float4& v);

#include "Float4.ipp"