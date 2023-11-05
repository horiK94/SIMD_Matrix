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
	Float3(const float* e);

	Float3(const float(&e)[3]); // float[3] の const 参照

	Float3 operator+(const Float3& v) const;
	Float3& operator+=(const Float3& v);
	Float3 operator+() const;
	Float3 operator-(const Float3& v) const;
	Float3& operator-=(const Float3& v);
	Float3 operator-() const;
	Float3 operator*(float k) const;
	friend Float3 operator*(float k, const Float3& v);
	Float3& operator*=(float k);
	Float3 operator/(float k) const;
	Float3& operator/=(float k);
	bool equal(const Float3& v, float epsilon = 0.01) const;
	bool isZero() const;

	float length() const;
	float squareLength() const;
	Float3& normalize();
	
	// 追加してみよう
	Float3 normalized();

	static float Dot(const Float3& v1, const Float3& v2);
	static Float3 Cross(const Float3& v1, const Float3& v2);
	static Float3 Normalize(const Float3& v);
};
std::ostream& operator<<(std::ostream& stream, const Float3& v);

inline Float3::Float3() : x(0), y(0), z(0)
{
}

inline Float3::Float3(NothingInit)
{
}

inline Float3::Float3(const float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{
}

inline Float3::Float3(const float e[3]) : x(e[0]), y(e[1]), z(e[2])
{
}

inline Float3::Float3(const float(&e)[3]) : x(e[0]), y(e[1]), z(e[2])
{
}

inline Float3 Float3::operator+(const Float3& v) const
{
	return Float3(x + v.x, y + v.y, z + v.z);
}

inline Float3& Float3::operator+=(const Float3& v)
{
	*this = Float3(x + v.x, y + v.y, z + v.z);
	return *this;
}

inline Float3 Float3::operator+() const
{
	return *this;
}

inline Float3 Float3::operator-(const Float3& v) const
{
	return Float3(x - v.x, y - v.y, z - v.z);
}

inline Float3& Float3::operator-=(const Float3& v)
{
	*this = Float3(x - v.x, y - v.y, z - v.z);
	return *this;
}

inline Float3 Float3::operator-() const
{
	return Float3(-x, -y, -z);
}

inline Float3 Float3::operator*(const float k) const
{
	return Float3(k * x, k * y, k * z);
}

inline Float3 operator*(const float k, const Float3& v)
{
	return Float3(k * v.x, k * v.y, k * v.z);
}

inline Float3& Float3::operator*=(const float k)
{
	*this = Float3(k * x, k * y, k * z);
	return *this;
}

inline Float3 Float3::operator/(const float k) const
{
	return Float3(1 / k * x, 1 / k * y, 1 / k * z);
}

inline Float3& Float3::operator/=(const float k)
{
	*this = Float3(1 / k * x, 1 / k * y, 1 / k * z);
	return *this;
}

inline bool Float3::equal(const Float3& v, const float epsilon) const
{
	return std::abs(x - v.x) <= epsilon
		&& std::abs(y - v.y) <= epsilon
		&& std::abs(z - v.z) <= epsilon;
}

inline bool Float3::isZero() const
{
	return x == 0
		&& y == 0
		&& z == 0;
}

inline float Float3::length() const
{
	return std::sqrt(squareLength());
}

inline float Float3::squareLength() const
{
	return x * x + y * y + z * z;
}

inline Float3& Float3::normalize()
{
	float len = length();
	float lenInv = 1 / len;

	*this = Float3(x * lenInv, y * lenInv, z * lenInv);
	return *this;
}

inline float Float3::Dot(const Float3& v1, const Float3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Float3 Float3::Cross(const Float3& v1, const Float3& v2)
{
	return Float3(
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	);
}

inline Float3 Float3::Normalize(const Float3& v)
{
	float len = v.length();
	float lenInv = 1 / len;

	return Float3(lenInv * v.x, lenInv * v.y, lenInv * v.z);
}

inline std::ostream& operator<<(std::ostream& stream, const Float3& v)
{
	return stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}