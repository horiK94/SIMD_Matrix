#pragma once
#include <iostream>

struct Float3
{
	float x;
	float y;
	float z;

	struct NothingInit {};

	Float3();
	Float3(NothingInit);
	Float3(const Float3& v) = default;
	Float3(float x, float y, float z);
	Float3 operator+(const Float3& v) const;
	Float3& operator+=(const Float3& v);
	Float3 operator+() const;
	Float3 operator-(const Float3& v) const;
	Float3& operator-=(const Float3& v);
	Float3 operator-() const;
	Float3 operator*(const float k) const;
	friend Float3 operator*(const float k, const Float3& v);

	Float3& operator*=(const float k);
	Float3 operator/(const float k) const;
	Float3& operator/=(const float k);
	bool operator==(const Float3 v) const;
	bool operator!=(const Float3 v) const;

	float length() const;
	float squareLength() const;
	Float3 normalize();
	static float Dot(const Float3& v1, const Float3& v2);
	static Float3 Cross(const Float3& v1, const Float3& v2);
	static Float3 Normalize(Float3& v);
};
std::ostream& operator<<(std::ostream& stream, const Float3& v);
