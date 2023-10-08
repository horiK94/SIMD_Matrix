#pragma once
#include "Float4.h"

struct Matrix4
{
	double m[4][4];

	Matrix4();
	struct NothingInit {};
	Matrix4(NothingInit);
	Matrix4(const Matrix4& v) = default;
	Matrix4(double m11, double m12, double m13, double m14,
		double m21, double m22, double m23, double m24,
		double m31, double m32, double m33, double m34,
		double m41, double m42, double m43, double m44);
	Matrix4(double m[4][4]);
	Matrix4(const Float4& v1,
		const Float4& v2,
		const Float4& v3,
		const Float4& v4);
	static Matrix4 Identity();
	Matrix4 operator+(const Matrix4 m) const;
	Matrix4 operator+() const;
	Matrix4& operator+=(const Matrix4 m);
	Matrix4 operator-(const Matrix4 m) const;
	Matrix4 operator-() const;
	Matrix4& operator-=(const Matrix4 m);
	Matrix4 operator*(double k) const;
	friend Matrix4 operator*(const double k, const Matrix4 m);
	Matrix4& operator*=(const double k);
	Matrix4 operator *(const Matrix4 m) const;
	Matrix4& operator*=(const Matrix4 m);
	Float4 operator*(const Float4 v) const;
	Float4& operator*=(const Float4 v);
	Matrix4 operator/(double k) const;
	Matrix4& operator/=(double	 k);
	double Det() const;
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

inline Matrix4::Matrix4(double m00, double m01, double m02, double m03,
	double m10, double m11, double m12, double m13,
	double m20, double m21, double m22, double m23,
	double m30, double m31, double m32, double m33)
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

inline Matrix4::Matrix4(double mat[4][4])
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

inline Matrix4 Matrix4::operator+(const Matrix4 m) const
{
	double elem[4][4];
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

inline Matrix4& Matrix4::operator+=(const Matrix4 m)
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

inline Matrix4 Matrix4::operator-(const Matrix4 m) const
{
	double elem[4][4];
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
	double elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elem[i][j] = -this->m[i][j];
		}
	}
	return Matrix4(elem);
}

inline Matrix4& Matrix4::operator-=(const Matrix4 m)
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

inline Matrix4 Matrix4::operator*(double k) const
{
	double elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elem[i][j] = this->m[i][j] * k;
		}
	}
	return Matrix4(elem);
}

inline Matrix4& Matrix4::operator*=(const double k)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m[i][j] = this->m[i][j] * k;
		}
	}
	return *this;
}

inline Matrix4 Matrix4::operator*(const Matrix4 m) const
{
	double elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			double sum = 0;
			for (int k = 0; k < 4; k++)
			{
				sum += this->m[i][k] * m.m[k][j];
			}

			elem[i][j] = sum;
		}
	}

	return Matrix4(elem);
}

inline Matrix4& Matrix4::operator*=(const Matrix4 m)
{
	double elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			double sum = 0;
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

inline Matrix4 operator*(const double k, const Matrix4 m)
{
	double elem[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elem[i][j] = k * m.m[i][j];
		}
	}
	return Matrix4(elem);
}