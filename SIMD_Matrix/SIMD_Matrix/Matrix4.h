#pragma once
#include "Float4.h"

class Matrix4
{
public:
	Float4 rowVec1;
	Float4 rowVec2;
	Float4 rowVec3;
	Float4 rowVec4;

	Matrix4();
	Matrix4(Float4 rowVec1, Float4 rowVec2, Float4 rowVec3, Float4 rowVec4);
	Matrix4 Identify() const;
	Matrix4 operator+(Matrix4 m);
	Matrix4 operator+();
	Matrix4 operator-(Matrix4 m);
	Matrix4 operator-();
	Matrix4 operator*(float k);
	friend Matrix4 operator*(const float k, const Matrix4 v);
	Matrix4 operator*(Matrix4 m);
};

