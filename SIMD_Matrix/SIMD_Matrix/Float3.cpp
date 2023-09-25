#include "Float3.h"

Float3::Float3() : x(0), y(0), z(0)
{
}

Float3::Float3(NothingInit)
{
}

Float3::Float3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{
}

Float3 Float3::operator+(const Float3& v) const
{
	return Float3(x + v.x, y + v.y, z + v.z);
}

Float3& Float3::operator+=(const Float3& v)
{
	*this = Float3(x + v.x, y + v.y, z + v.z);
	return *this;
}

Float3 Float3::operator+() const
{
	return *this;
}

Float3 Float3::operator-(const Float3& v) const
{
	return Float3(x - v.x, y - v.y, z - v.z);
}

Float3& Float3::operator-=(const Float3& v)
{
	*this = Float3(x - v.x, y - v.y, z - v.z);
	return *this;
}

Float3 Float3::operator-() const
{
	return Float3(-x, -y, -z);
}

Float3 Float3::operator*(const float k) const
{
	return Float3(k * x, k * y, k * z);
}

Float3 operator*(const float k, const Float3& v)
{
	return Float3(k * v.x, k * v.y, k * v.z);
}

Float3& Float3::operator*=(const float k)
{
	*this = Float3(k * x, k * y, k * z);
	return *this;
}

Float3 Float3::operator/(const float k) const
{
	return Float3(1 / k * x, 1 / k * y, 1 / k * z);
}

Float3& Float3::operator/=(const float k)
{
	*this = Float3(1 / k * x, 1 / k * y, 1 / k * z);
	return *this;
}

bool Float3::operator==(const Float3 v) const
{
	return x == v.x
		&& y == v.y
		&& z == v.z;
}

bool Float3::operator!=(const Float3 v) const
{
	return !(*this == v);
}

float Float3::length() const
{
	return sqrt(squareLength());
}

float Float3::squareLength() const
{
	return Dot(*this, *this);
}

Float3 Float3::normalize()
{
	float len = length();
	float lenInv = 1 / len;

	*this = Float3(x * lenInv, y * lenInv, z * lenInv);
	return *this;
}

float Float3::Dot(const Float3& v1, const Float3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Float3 Float3::Cross(const Float3& v1, const Float3& v2)
{
	return Float3(
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	);
}

Float3 Float3::Normalize(Float3& v)
{
	float len = v.length();
	float lenInv = 1 / len;

	return Float3(lenInv * v.x, lenInv * v.y, lenInv * v.z);
}

std::ostream& operator<<(std::ostream& stream, const Float3& v)
{
	return stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}