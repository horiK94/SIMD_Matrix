#include <iostream>

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

	Float4 operator+(Float4 m)
	{
		return Float4(x + m.x, y + m.y, z + m.z, w + m.w);
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

int main()
{
	Float4 a = Float4(1, 2, 3, 4);
	Float4 b = Float4(-2.5f, 5, -7.5f, 10);
	std::cout << (a + b) << std::endl;
}

