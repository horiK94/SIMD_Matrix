#include "Matrix4.h"

Matrix4::Matrix4() : rowVec1(Float4()), rowVec2(Float4()), rowVec3(Float4()), rowVec4(Float4())
{
}

Matrix4::Matrix4(Float4 rowVec1, Float4 rowVec2, Float4 rowVec3, Float4 rowVec4) : rowVec1(rowVec1), rowVec2(rowVec2), rowVec3(rowVec3), rowVec4(rowVec4)
{
}

Matrix4 Matrix4::Identify() const
{
	return Matrix4(
		Float4(1, 0, 0, 0),
		Float4(0, 1, 0, 0),
		Float4(0, 0, 1, 0),
		Float4(0, 0, 0, 1)
	);
}

Matrix4 Matrix4::operator+(Matrix4 m)
{
	return Matrix4(
		rowVec1 + m.rowVec1,
		rowVec2 + m.rowVec2,
		rowVec3 + m.rowVec3,
		rowVec4 + m.rowVec4
	);
}

Matrix4 Matrix4::operator+()
{
	return *this;
}

Matrix4 Matrix4::operator-(Matrix4 m)
{
	return *this + (-m);
}

Matrix4 Matrix4::operator-()
{
	return -1 * *this;
}

Matrix4 Matrix4::operator*(float k)
{
	return Matrix4(
		rowVec1 * k,
		rowVec2 * k,
		rowVec3 * k,
		rowVec4 * k
	);
}

Matrix4 Matrix4::operator*(Matrix4 m)
{
	Float4 column1Vec(rowVec1.x, rowVec2.x, rowVec3.x, rowVec4.x);
	Float4 column2Vec(rowVec1.y, rowVec2.y, rowVec3.y, rowVec4.y);
	Float4 column3Vec(rowVec1.z, rowVec2.z, rowVec3.z, rowVec4.z);
	Float4 column4Vec(rowVec1.w, rowVec2.w, rowVec3.w, rowVec4.w);

	return Matrix4(
		Float4(Float4::Dot(rowVec1, column1Vec), Float4::Dot(rowVec1, column2Vec), Float4::Dot(rowVec1, column3Vec), Float4::Dot(rowVec1, column4Vec)),
		Float4(Float4::Dot(rowVec2, column1Vec), Float4::Dot(rowVec2, column2Vec), Float4::Dot(rowVec2, column3Vec), Float4::Dot(rowVec2, column4Vec)),
		Float4(Float4::Dot(rowVec3, column1Vec), Float4::Dot(rowVec3, column2Vec), Float4::Dot(rowVec3, column3Vec), Float4::Dot(rowVec3, column4Vec)),
		Float4(Float4::Dot(rowVec4, column1Vec), Float4::Dot(rowVec4, column2Vec), Float4::Dot(rowVec4, column3Vec), Float4::Dot(rowVec4, column4Vec))
	);
}

Matrix4 operator*(const float k, const Matrix4 v)
{
	return Matrix4(
		k * v.rowVec1,
		k * v.rowVec2,
		k * v.rowVec3,
		k * v.rowVec4
	);
}
