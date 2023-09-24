#include <iostream>
using namespace std;
#include "Float3.h"
#include "Float4.h"

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