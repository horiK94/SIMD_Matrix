#include <iostream>
using namespace std;
#include "Float3.h"

class Float4
{
public:
	float x;
	float y;
	float z;
	float w;

	Float4() : x(0), y(0), z(0), w(0)
	{
	}

	Float4(Float4* v) : x(v->x), y(v->y), z(v->z), w(v->w)
	{
	}

	Float4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
	{
	}

	Float4(Float3 v, float w) : x(v.x), y(v.y), z(v.z), w(w)
	{

	}

	Float4 operator+(const Float4 m) const
	{
		return Float4(x + m.x, y + m.y, z + m.z, w + m.w);
	}

	Float4 operator+=(const Float4 v)
	{
		*this = *this + v;
		return *this;
	}

	Float4 operator+() const
	{
		return *this;
	}

	Float4 operator-(const Float4 m) const
	{
		return *this + (-m);
	}

	Float4 operator-=(const Float4 v)
	{
		*this = *this - v;
		return *this;
	}

	Float4 operator-() const
	{
		return -1 * *this;
	}

	Float4 operator*(const float k)
	{
		return Float4(k * x, k * y, k * z, k * w);
	}

	friend Float4 operator*(const float k, const Float4 v)
	{
		return Float4(k * v.x, k * v.y, k * v.z, k * v.w);
	}

	Float4 operator*=(const float k)
	{
		*this = k * *this;
		return *this;
	}

	Float4 operator/(const float k) const
	{
		return (1 / k) * *this;
	}

	Float4 operator/=(const float k)
	{
		*this = *this / k;
		return *this;
	}

	bool operator==(const Float4& v) const
	{
		return x == v.x
			&& y == v.y
			&& z == v.z
			&& w == v.w;
	}

	bool operator!=(const Float4& v) const
	{
		return !(*this == v);
	}

	static float Dot(const Float4 v1, const Float4 v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	}
};

class Matrix4
{
public:
	Float4 rowVec1;
	Float4 rowVec2;
	Float4 rowVec3;
	Float4 rowVec4;

	Matrix4() : rowVec1(Float4()), rowVec2(Float4()), rowVec3(Float4()), rowVec4(Float4())
	{

	}

	Matrix4(Float4 rowVec1, Float4 rowVec2, Float4 rowVec3, Float4 rowVec4) : rowVec1(rowVec1), rowVec2(rowVec2), rowVec3(rowVec3), rowVec4(rowVec4)
	{
	}

	Matrix4 Identify() const
	{
		return Matrix4(
			Float4(1, 0, 0, 0),
			Float4(0, 1, 0, 0),
			Float4(0, 0, 1, 0),
			Float4(0, 0, 0, 1)
		);
	}

	Matrix4 operator+(Matrix4 m)
	{
		return Matrix4(
			rowVec1 + m.rowVec1,
			rowVec2 + m.rowVec2,
			rowVec3 + m.rowVec3,
			rowVec4 + m.rowVec4
		);
	}

	Matrix4 operator+()
	{
		return *this;
	}

	Matrix4 operator-(Matrix4 m)
	{
		return *this + (-m);
	}

	Matrix4 operator-()
	{
		return -1 * *this;
	}

	Matrix4 operator*(float k)
	{
		return Matrix4(
			rowVec1 * k,
			rowVec2 * k,
			rowVec3 * k,
			rowVec4 * k
		);
	}

	friend Matrix4 operator*(const float k, const Matrix4 v)
	{
		return Matrix4(
			k * v.rowVec1,
			k * v.rowVec2,
			k * v.rowVec3,
			k * v.rowVec4
		);
	}

};


std::ostream& operator<<(std::ostream& stream, const Float4& v)
{
	stream << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	return stream;
}
std::ostream& operator<<(std::ostream& stream, const Float3& v)
{
	stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return stream;
}

int main()
{
	Float4 a(1, 2, 3, 4);
	Float4 b(-2.5f, 5, -7.5f, 10);

	cout << Float4(Float3(1, 2, 3), -1) << endl;

	cout << (a + b) << endl;
	cout << (a - b) << endl;
	cout << +a << endl;
	cout << -a << endl;
	cout << (a * 0.5) << endl;
	cout << (0.5 * a) << endl;
	cout << (a / 2) << endl;
	cout << (Float4::Dot(a, b)) << endl;
	cout << endl;
	a += b;
	cout << a << endl;
	a -= b;
	cout << a << endl;
	a *= 2;
	cout << a << endl;
	a /= 2;
	cout << a << endl;
	cout << (a == Float4(1, 2, 3, 0)) << endl;
	cout << (a == Float4(1, 2, 3, 4)) << endl;
	cout << (a != b) << endl;
	cout << endl;
	cout << endl;

	Float3 c(2, 3, 1);
	Float3 d(-3, 1, 4);

	cout << (c + d) << endl;
	cout << (c - d) << endl;
	cout << +c << endl;
	cout << -c << endl;
	cout << (3 * c) << endl;
	cout << (d / 2) << endl;
	cout << (Float3::Dot(c, d)) << endl;
	cout << (Float3::Cross(c, d)) << endl;
	cout << endl;
	c += d;
	cout << c << endl;
	c -= d;
	cout << c << endl;
	c *= 2;
	cout << c << endl;
	c /= 2;
	cout << c << endl;
	cout << (c == Float3(2, 3, 0)) << endl;
	cout << (c == Float3(2, 3, 1)) << endl;
	cout << (c != d) << endl;
}