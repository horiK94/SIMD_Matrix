#pragma once
#include <iostream>

class Float3
{
public:
	float x;
	float y;
	float z;

	Float3();
	Float3(Float3* v);
	Float3(float x, float y, float z);
	Float3 operator+(const Float3 v) const;
	Float3 operator+=(const Float3 v);
	Float3 operator+() const;
	Float3 operator-(const Float3 v) const;
	Float3 operator-=(const Float3 v);
	Float3 operator-() const;
	Float3 operator*(const float k) const;
	friend Float3 operator*(const float k, const Float3 v);

	Float3 operator*=(const float k);
	Float3 operator/(const float k) const;
	Float3 operator/=(const float k);
	bool operator==(const Float3 v) const;
	bool operator!=(const Float3 v) const;

	float Magnitude();
	float SqrtMagnitude();
	void Normalize();
	static float Dot(const Float3 v1, const Float3 v2);
	static Float3 Cross(const Float3 v1, const Float3 v2);
	static Float3 Normalize(Float3 v);
};
std::ostream& operator<<(std::ostream& stream, const Float3& v);
