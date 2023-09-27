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

inline Float4::Float4() : x(0), y(0), z(0), w(0)
{
}

inline Float4::Float4(NothingInit)
{
}

inline Float4::Float4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w)
{
}

inline Float4::Float4(const Float3& v, float w) : x(v.x), y(v.y), z(v.z), w(w)
{
}

inline Float4 Float4::operator+(const Float4& v) const
{
	return Float4(x + v.x, y + v.y, z + v.z, w + v.w);
}

inline Float4& Float4::operator+=(const Float4& v)
{
	*this = Float4(x + v.x, y + v.y, z + v.z, w + v.w);
	return *this;
}

inline Float4 Float4::operator+() const
{
	return *this;
}

inline Float4 Float4::operator-(const Float4& v) const
{
	return Float4(x - v.x, y - v.y, z - v.z, w - v.w);
}

inline Float4& Float4::operator-=(const Float4& v)
{
	*this = Float4(x - v.x, y - v.y, z - v.z, w - v.w);
	return *this;
}

inline Float4 Float4::operator-() const
{
	return Float4(-x, -y, -z, -w);
}

inline Float4 Float4::operator*(const float k)
{
	return Float4(k * x, k * y, k * z, k * w);
}

inline Float4 operator*(const float k, const Float4& v)
{
	return Float4(k * v.x, k * v.y, k * v.z, k * v.w);
}

inline Float4& Float4::operator*=(const float k)
{
	*this = Float4(k * x, k * y, k * z, k * w);
	return *this;
}

inline Float4 Float4::operator/(const float k) const
{
	return Float4(1 / k * x, 1 / k * y, 1 / k * z, 1 / k * w);
}

inline Float4& Float4::operator/=(const float k)
{
	*this = Float4(1 / k * x, 1 / k * y, 1 / k * z, 1 / k * w);
	return *this;
}

inline bool Float4::equal(const Float4& v, const float epsilon) const
{
	return std::abs(x - v.x) <= epsilon
		&& std::abs(y - v.y) <= epsilon
		&& std::abs(z - v.z) <= epsilon
		&& std::abs(w - v.w) <= epsilon;
}

inline bool Float4::isZero() const
{
	return x == 0
		&& y == 0
		&& z == 0
		&& w == 0;
}

inline float Float4::length() const
{
	return std::sqrt(squareLength());
}

inline float Float4::squareLength() const
{
	return x * x + y * y + z * z + w * w;
}

inline Float4& Float4::normalize()
{
	float len = length();
	float lenInv = 1 / len;

	*this = Float4(x * lenInv, y * lenInv, z * lenInv, w * lenInv);
	return *this;
}

inline float Float4::Dot(const Float4& v1, const Float4& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

inline Float4 Float4::Normalize(const Float4& v)
{
	float len = v.length();
	float lenInv = 1 / len;

	return Float4(lenInv * v.x, lenInv * v.y, lenInv * v.z, lenInv  * v.w);
}

inline std::ostream& operator<<(std::ostream& stream, const Float4& v)
{
	return stream << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
}
