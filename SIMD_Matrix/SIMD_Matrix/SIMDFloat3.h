#pragma once
#include <iostream>

struct SIMDFloat3
{
	float x;
	float y;
	float z;

	struct NothingInit {};

	SIMDFloat3();
	SIMDFloat3(NothingInit);
	SIMDFloat3(const SIMDFloat3& v) = default;
	SIMDFloat3(float x, float y, float z);
	SIMDFloat3(const float e[3]);
	SIMDFloat3 operator+(const SIMDFloat3& v) const;
	SIMDFloat3& operator+=(const SIMDFloat3& v);
	SIMDFloat3 operator+() const;
	SIMDFloat3 operator-(const SIMDFloat3& v) const;
	SIMDFloat3& operator-=(const SIMDFloat3& v);
	SIMDFloat3 operator-() const;
	SIMDFloat3 operator*(const float k) const;
	friend SIMDFloat3 operator*(const float k, const SIMDFloat3& v);
	SIMDFloat3& operator*=(const float k);
	SIMDFloat3 operator/(const float k) const;
	SIMDFloat3& operator/=(const float k);
	bool equal(const SIMDFloat3& v, const float epsilon = 0.01) const;
	bool isZero() const;

	float length() const;
	float squareLength() const;
	SIMDFloat3& normalize();

	static float Dot(const SIMDFloat3& v1, const SIMDFloat3& v2);
	static SIMDFloat3 Cross(const SIMDFloat3& v1, const SIMDFloat3& v2);
	static SIMDFloat3 Normalize(const SIMDFloat3& v);
};
std::ostream& operator<<(std::ostream& stream, const SIMDFloat3& v);

inline SIMDFloat3::SIMDFloat3()
{
}

inline SIMDFloat3::SIMDFloat3(NothingInit)
{
}

inline SIMDFloat3::SIMDFloat3(float _x, float _y, float _z)
{
}

inline SIMDFloat3::SIMDFloat3(const float e[3])
{
}

inline SIMDFloat3 SIMDFloat3::operator+(const SIMDFloat3& v) const
{
	return SIMDFloat3();
}

inline SIMDFloat3& SIMDFloat3::operator+=(const SIMDFloat3& v)
{
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator+() const
{
	return SIMDFloat3();
}

inline SIMDFloat3 SIMDFloat3::operator-(const SIMDFloat3& v) const
{
	return SIMDFloat3();
}

inline SIMDFloat3& SIMDFloat3::operator-=(const SIMDFloat3& v)
{
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator-() const
{
	return SIMDFloat3();
}

inline SIMDFloat3 SIMDFloat3::operator*(const float k) const
{
	return SIMDFloat3();
}

inline SIMDFloat3 operator*(const float k, const SIMDFloat3& v)
{
	return SIMDFloat3(k * v.x, k * v.y, k * v.z);
}

inline SIMDFloat3& SIMDFloat3::operator*=(const float k)
{
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator/(const float k) const
{
	return SIMDFloat3();
}

inline SIMDFloat3& SIMDFloat3::operator/=(const float k)
{
	return *this;
}

inline bool SIMDFloat3::equal(const SIMDFloat3& v, const float epsilon) const
{
	return false;
}

inline bool SIMDFloat3::isZero() const
{
	return false;
}

inline float SIMDFloat3::length() const
{
	return 0.0f;
}

inline float SIMDFloat3::squareLength() const
{
	return 0.0f;
}

inline SIMDFloat3& SIMDFloat3::normalize()
{
	return *this;
}

inline float SIMDFloat3::Dot(const SIMDFloat3& v1, const SIMDFloat3& v2)
{
	return 0.0f;
}

inline SIMDFloat3 SIMDFloat3::Cross(const SIMDFloat3& v1, const SIMDFloat3& v2)
{
	return SIMDFloat3();
}

inline SIMDFloat3 SIMDFloat3::Normalize(const SIMDFloat3& v)
{
	return SIMDFloat3();
}

inline std::ostream& operator<<(std::ostream& stream, const SIMDFloat3& v)
{
	return stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}