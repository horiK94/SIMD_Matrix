#pragma once
#include "Float3.h"
#include <iostream>

class Float4
{
public:
	float x;
	float y;
	float z;
	float w;

	Float4();
	Float4(Float4* v);
	Float4(float x, float y, float z, float w);
	Float4(Float3 v, float w);
	Float4 operator+(const Float4 m) const;
	Float4 operator+=(const Float4 v);
	Float4 operator+() const;
	Float4 operator-(const Float4 m) const;
	Float4 operator-=(const Float4 v);
	Float4 operator-() const;
	Float4 operator*(const float k);
	friend Float4 operator*(const float k, const Float4 v);
	Float4 operator*=(const float k);
	Float4 operator/(const float k) const;
	Float4 operator/=(const float k);
	bool operator==(const Float4 v) const;
	bool operator!=(const Float4 v) const;

	float Magnitude();
	float SqrtMagnitude();
	void Normalize();
	static float Dot(const Float4 v1, const Float4 v2);
	static Float3 Normalize(Float3 v);
};
std::ostream& operator<<(std::ostream& stream, const Float4& v);