#pragma once
#include "Float4.h"
#include <vector>

struct Matrix4
{
	float m[4][4];

	Matrix4();
	struct NothingInit {};
	Matrix4(NothingInit);
	Matrix4(const Matrix4& v) = default;
	Matrix4(float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44);
	Matrix4(float m[4][4]);
	Matrix4(const Float4& v1, const Float4& v2, const Float4& v3, const Float4& v4);
	static Matrix4 Identity();
	Matrix4 operator+(const Matrix4& m) const;
	Matrix4 operator+() const;
	Matrix4& operator+=(const Matrix4& m);
	Matrix4 operator-(const Matrix4& m) const;
	Matrix4 operator-() const;
	Matrix4& operator-=(const Matrix4& m);
	Matrix4 operator*(float k) const;
	friend Matrix4 operator*(const float k, const Matrix4& m);
	Matrix4& operator*=(const float k);
	Matrix4 operator *(const Matrix4& m) const;
	Matrix4& operator*=(const Matrix4& m);
	friend Float4 operator*(const Float4& v, const Matrix4& m);
	friend Float4& operator*=(const Float4& v, const Matrix4& m);
	Matrix4 operator/(float k) const;
	Matrix4& operator/=(float k);
	float det() const;
};

#include "Matrix4.ipp"