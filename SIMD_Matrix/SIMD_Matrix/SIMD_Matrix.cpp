#include <iostream>
using namespace std;

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

	Float4 operator+(const Float4 m) const
	{
		return Float4(x + m.x, y + m.y, z + m.z, w + m.w);
	}

	Float4 operator-(const Float4 m) const
	{
		return Float4(x - m.x, y - m.y, z - m.z, w - m.w);
	}

	friend Float4 operator*(const float k, const Float4& v)
	{
		return Float4(k * v.x, k * v.y, k * v.z, k * v.w);
	}

	Float4 operator/(const float k) const
	{
		return (1 / k) * *this;
	}

	static float Dot(const Float4 v1, const Float4 v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	}
};

class Float3
{
public:
	float x;
	float y;
	float z;

	Float3() : x(0), y(0), z(0)
	{
	}

	Float3(Float4* v) : x(v->x), y(v->y), z(v->z)
	{
	}

	Float3(float x, float y, float z) : x(x), y(y), z(z)
	{
	}

	Float3 operator+(const Float3 m) const
	{
		return Float3(x + m.x, y + m.y, z + m.z);
	}

	Float3 operator-(const Float3 m) const
	{
		return Float3(x - m.x, y - m.y, z - m.z);
	}

	friend Float3 operator*(const float k, const Float3& v)
	{
		return Float3(k * v.x, k * v.y, k * v.z);
	}

	Float3 operator/(const float k) const
	{
		return (1 / k) * *this;
	}

	static float Dot(const Float3 v1, const Float3 v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	static Float3 Cross(const Float3 v1, const Float3 v2)
	{
		return Float3(
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x
		);
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
		return Matrix4();
	}

	Matrix4 operator-()
	{
		return Matrix4();
	}

	Matrix4 operator-(Matrix4 m)
	{
		return Matrix4();
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
	Float4 a = Float4(1, 2, 3, 4);
	Float4 b = Float4(-2.5f, 5, -7.5f, 10);

	cout << (a + b) << endl;
	cout << (a - b) << endl;
	cout << (0.5 * a) << endl;
	cout << (a / 2) << endl;
	cout << (Float4::Dot(a, b)) << endl;

	Float3 c = Float3(2, 3, 1);
	Float3 d = Float3(-3, 1, 4);

	cout << (c + d) << endl;
	cout << (c - d) << endl;
	cout << (3 * c) << endl;
	cout << (d / 2) << endl;
	cout << (Float3::Dot(c, d)) << endl;
	cout << (Float3::Cross(c, d)) << endl;
}