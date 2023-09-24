#include "Float3.h"

Float3::Float3() : x(0), y(0), z(0)
{
}

Float3::Float3(Float3* v) : x(v->x), y(v->y), z(v->z)
{
}

Float3::Float3(float x, float y, float z) : x(x), y(y), z(z)
{
}

Float3 Float3::operator+(const Float3 v) const
{
	return Float3(x + v.x, y + v.y, z + v.z);
}

Float3 Float3::operator+=(const Float3 v)
{
	*this = *this + v;
	return *this;
}

Float3 Float3::operator+() const
{
	return *this;
}

Float3 Float3::operator-(const Float3 v) const
{
	return *this + (-v);
}

Float3 Float3::operator-=(const Float3 v)
{
	*this = *this - v;
	return *this;
}

Float3 Float3::operator-() const
{
	return -1 * *this;
}

Float3 Float3::operator*(const float k) const
{
	return Float3(k * x, k * y, k * z);
}

Float3 operator*(const float k, const Float3 v)
{
	return Float3(k * v.x, k * v.y, k * v.z);
}

Float3 Float3::operator*=(const float k)
{
	*this = k * *this;
	return *this;
}

Float3 Float3::operator/(const float k) const
{
	return (1 / k) * *this;
}

Float3 Float3::operator/=(const float k)
{
	*this = *this / k;
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

float Float3::Dot(const Float3 v1, const Float3 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Float3 Float3::Cross(const Float3 v1, const Float3 v2)
{
	return Float3(
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	);
}

std::ostream& operator<<(std::ostream& stream, const Float3& v)
{
	stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return stream;
}