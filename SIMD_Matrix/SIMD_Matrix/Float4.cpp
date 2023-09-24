#include "Float4.h"

Float4::Float4() : x(0), y(0), z(0), w(0)
{
}

Float4::Float4(Float4* v) : x(v->x), y(v->y), z(v->z), w(v->w)
{
}

Float4::Float4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

Float4::Float4(Float3 v, float w) : x(v.x), y(v.y), z(v.z), w(w)
{
}

Float4 Float4::operator+(const Float4 m) const
{
	return Float4(x + m.x, y + m.y, z + m.z, w + m.w);
}

Float4 Float4::operator+=(const Float4 v)
{
	*this = *this + v;
	return *this;
}

Float4 Float4::operator+() const
{
	return *this;
}

Float4 Float4::operator-(const Float4 m) const
{
	return *this + (-m);
}

Float4 Float4::operator-=(const Float4 v)
{
	*this = *this - v;
	return *this;
}

Float4 Float4::operator-() const
{
	return -1 * *this;
}

Float4 Float4::operator*(const float k)
{
	return Float4(k * x, k * y, k * z, k * w);
}

Float4 operator*(const float k, const Float4 v)
{
	return Float4(k * v.x, k * v.y, k * v.z, k * v.w);
}

Float4 Float4::operator*=(const float k)
{
	*this = k * *this;
	return *this;
}

Float4 Float4::operator/(const float k) const
{
	return (1 / k) * *this;
}

Float4 Float4::operator/=(const float k)
{
	*this = *this / k;
	return *this;
}

bool Float4::operator==(const Float4 v) const
{
	return x == v.x
		&& y == v.y
		&& z == v.z
		&& w == v.w;
}

bool Float4::operator!=(const Float4 v) const
{
	return !(*this == v);
}

float Float4::Magnitude()
{
	return sqrt(SqrtMagnitude());
}

float Float4::SqrtMagnitude()
{
	return Dot(*this, *this);
}

void Float4::Normalize()
{
	*this /= Magnitude();
}

float Float4::Dot(const Float4 v1, const Float4 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

Float3 Float4::Normalize(Float3 v)
{
	return v / v.Magnitude();
}

std::ostream& operator<<(std::ostream& stream, const Float4& v)
{
	stream << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	return stream;
}