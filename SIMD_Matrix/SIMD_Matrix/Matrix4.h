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

inline  Matrix4::Matrix4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m[i][j] = 0;
		}
	}
}

inline Matrix4::Matrix4(NothingInit)
{
}

inline Matrix4::Matrix4(
	float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33)
{
	m[0][0] = m00;
	m[0][1] = m01;
	m[0][2] = m02;
	m[0][3] = m03;

	m[1][0] = m10;
	m[1][1] = m11;
	m[1][2] = m12;
	m[1][3] = m13;

	m[2][0] = m20;
	m[2][1] = m21;
	m[2][2] = m22;
	m[2][3] = m23;

	m[3][0] = m30;
	m[3][1] = m31;
	m[3][2] = m32;
	m[3][3] = m33;
}

inline Matrix4::Matrix4(float mat[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m[i][j] = mat[i][j];
		}
	}
}

inline Matrix4::Matrix4(const Float4& v1, const Float4& v2, const Float4& v3, const Float4& v4)
{
	m[0][0] = v1.x;
	m[0][1] = v1.y;
	m[0][2] = v1.z;
	m[0][3] = v1.w;

	m[1][0] = v2.x;
	m[1][1] = v2.y;
	m[1][2] = v2.z;
	m[1][3] = v2.w;

	m[2][0] = v3.x;
	m[2][1] = v3.y;
	m[2][2] = v3.z;
	m[2][3] = v3.w;

	m[3][0] = v4.x;
	m[3][1] = v4.y;
	m[3][2] = v4.z;
	m[3][3] = v4.w;
}

inline Matrix4 Matrix4::Identity()
{
	return Matrix4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
}

inline Matrix4 Matrix4::operator+(const Matrix4& m) const
{
	float elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elem[i][j] = this->m[i][j] + m.m[i][j];
		}
	}

	return Matrix4(elem);
}

inline Matrix4 Matrix4::operator+() const
{
	return *this;
}

inline Matrix4& Matrix4::operator+=(const Matrix4& m)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m[i][j] += m.m[i][j];
		}
	}

	return *this;
}

inline Matrix4 Matrix4::operator-(const Matrix4& m) const
{
	float elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elem[i][j] = this->m[i][j] - m.m[i][j];
		}
	}

	return Matrix4(elem);
}

inline Matrix4 Matrix4::operator-() const
{
	float elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elem[i][j] = -this->m[i][j];
		}
	}
	return Matrix4(elem);
}

inline Matrix4& Matrix4::operator-=(const Matrix4& m)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m[i][j] -= m.m[i][j];
		}
	}
	return *this;
}

inline Matrix4 Matrix4::operator*(float k) const
{
	float elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elem[i][j] = this->m[i][j] * k;
		}
	}
	return Matrix4(elem);
}

inline Matrix4 operator*(const float k, const Matrix4& m)
{
	float elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elem[i][j] = k * m.m[i][j];
		}
	}
	return Matrix4(elem);
}

inline Float4 operator*(const Float4& v, const Matrix4& m)
{
	float elem[4];
	for (int i = 0; i < 4; i++)
	{
		elem[i] = m.m[0][i] * v.x
			+ m.m[1][i] * v.y
			+ m.m[2][i] * v.z
			+ m.m[3][i] * v.w;
	}

	return Float4(elem);
}

inline Float4& operator*=(const Float4& v, const Matrix4& m)
{
	float elem[4];
	for (int i = 0; i < 4; i++)
	{
		elem[i] = m.m[0][i] * v.x
			+ m.m[1][i] * v.y
			+ m.m[2][i] * v.z
			+ m.m[3][i] * v.w;
	}

	Float4 calc(elem);
	return calc;
}

inline Matrix4& Matrix4::operator*=(const float k)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m[i][j] *= k;
		}
	}
	return *this;
}

inline Matrix4 Matrix4::operator*(const Matrix4& m) const
{
	float elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float sum = 0;
			for (int k = 0; k < 4; k++)
			{
				sum += this->m[i][k] * m.m[k][j];
			}

			elem[i][j] = sum;
		}
	}

	return Matrix4(elem);
}

inline Matrix4& Matrix4::operator*=(const Matrix4& m)
{
	float elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float sum = 0;
			for (int k = 0; k < 4; k++)
			{
				sum += this->m[i][k] * m.m[k][j];
			}

			elem[i][j] = sum;
		}
	}

	*this = Matrix4(elem);
	return *this;
}

inline Matrix4 Matrix4::operator/(float k) const
{
	float elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elem[i][j] = this->m[i][j] / k;
		}
	}

	return Matrix4(elem);
}

inline Matrix4& Matrix4::operator/=(float k)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m[i][j] /= k;
		}
	}
	return *this;
}

inline float Matrix4::det() const
{
	return m[0][0] * m[1][1] * m[2][2] * m[3][3]
		- m[0][0] * m[1][1] * m[2][3] * m[3][2]
		- m[0][0] * m[2][1] * m[1][2] * m[3][3]
		+ m[0][0] * m[2][1] * m[1][3] * m[3][2]
		+ m[0][0] * m[3][1] * m[1][2] * m[2][3]
		- m[0][0] * m[3][1] * m[1][3] * m[2][2]
		- m[1][0] * m[0][1] * m[2][2] * m[3][3]
		+ m[1][0] * m[0][1] * m[2][3] * m[3][2]
		+ m[1][0] * m[2][1] * m[0][2] * m[3][3]
		- m[1][0] * m[2][1] * m[0][3] * m[3][2]
		- m[1][0] * m[3][1] * m[0][2] * m[2][3]
		+ m[1][0] * m[3][1] * m[0][3] * m[2][2]
		+ m[2][0] * m[0][1] * m[1][2] * m[3][3]
		- m[2][0] * m[0][1] * m[1][3] * m[3][2]
		- m[2][0] * m[1][1] * m[0][2] * m[3][3]
		+ m[2][0] * m[1][1] * m[0][3] * m[3][2]
		+ m[2][0] * m[3][1] * m[0][2] * m[1][3]
		- m[2][0] * m[3][1] * m[0][3] * m[1][2]
		- m[3][0] * m[0][1] * m[1][2] * m[2][3]
		+ m[3][0] * m[0][1] * m[1][3] * m[2][2]
		+ m[3][0] * m[1][1] * m[0][2] * m[2][3]
		- m[3][0] * m[1][1] * m[0][3] * m[2][2]
		- m[3][0] * m[2][1] * m[0][2] * m[1][3]
		+ m[3][0] * m[2][1] * m[0][3] * m[1][2];
}