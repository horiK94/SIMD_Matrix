#pragma once
#include "SIMDMatrix4.h"
#include "ThirdParty/doctest/doctest.h"
#include <xmmintrin.h>

TEST_CASE("SIMDMatrix4 zero matrix construct")
{
	SIMDMatrix4 zeroMat = SIMDMatrix4();
	CHECK(SIMDFloat4(zeroMat.v[0]).isZero());
	CHECK(SIMDFloat4(zeroMat.v[1]).isZero());
	CHECK(SIMDFloat4(zeroMat.v[2]).isZero());
	CHECK(SIMDFloat4(zeroMat.v[3]).isZero());
}


TEST_CASE("SIMDMatrix4 construct init SIMDMatrix4")
{
	SIMDMatrix4 m(
		1.3, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 0, -23.4f
	);
	SIMDMatrix4 mat(m);

	CHECK(SIMDFloat4(m.v[0]).equal(SIMDFloat4(1.3, 2, 3, 4)));
	CHECK(SIMDFloat4(m.v[1]).equal(SIMDFloat4(5, 6, 7, 8)));
	CHECK(SIMDFloat4(m.v[2]).equal(SIMDFloat4(9, 10, 11, 12)));
	CHECK(SIMDFloat4(m.v[3]).equal(SIMDFloat4(13, 14, 0, -23.4f)));
}

TEST_CASE("SIMDMatrix4 each element construct")
{
	SIMDMatrix4 m(
		1.3, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 0, -23.4f
	);

	CHECK(SIMDFloat4(m.v[0]).equal(SIMDFloat4(1.3, 2, 3, 4)));
	CHECK(SIMDFloat4(m.v[1]).equal(SIMDFloat4(5, 6, 7, 8)));
	CHECK(SIMDFloat4(m.v[2]).equal(SIMDFloat4(9, 10, 11, 12)));
	CHECK(SIMDFloat4(m.v[3]).equal(SIMDFloat4(13, 14, 0, -23.4f)));
}

TEST_CASE("SIMDMatrix4 double array construct")
{
	float elem[4][4] = {
		{1.3, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 0, -23.4f}
	};

	SIMDMatrix4 m(elem);

	CHECK(SIMDFloat4(m.v[0]).equal(SIMDFloat4(1.3, 2, 3, 4)));
	CHECK(SIMDFloat4(m.v[1]).equal(SIMDFloat4(5, 6, 7, 8)));
	CHECK(SIMDFloat4(m.v[2]).equal(SIMDFloat4(9, 10, 11, 12)));
	CHECK(SIMDFloat4(m.v[3]).equal(SIMDFloat4(13, 14, 0, -23.4f)));
}

TEST_CASE("SIMDMatrix4 each SIMDFloat4 construct")
{
	SIMDMatrix4 m(SIMDFloat4(1.3, 2, 3, 4), SIMDFloat4(5, 6, 7, 8), SIMDFloat4(9, 10, 11, 12), SIMDFloat4(13, 14, 0, -23.4f));

	CHECK(SIMDFloat4(m.v[0]).equal(SIMDFloat4(1.3, 2, 3, 4)));
	CHECK(SIMDFloat4(m.v[1]).equal(SIMDFloat4(5, 6, 7, 8)));
	CHECK(SIMDFloat4(m.v[2]).equal(SIMDFloat4(9, 10, 11, 12)));
	CHECK(SIMDFloat4(m.v[3]).equal(SIMDFloat4(13, 14, 0, -23.4f)));
}

TEST_CASE("SIMDMatrix4 each __m128 construct")
{
	__m128 m[4];
	m[0] = _mm_set_ps(4, 3, 2, 1.3);
	m[1] = _mm_set_ps(8, 7, 6, 5);
	m[2] = _mm_set_ps(12, 11, 10, 9);
	m[3] = _mm_set_ps(-23.4, 0, 14, 13);

	SIMDMatrix4 mat(m);

	CHECK(SIMDFloat4(mat.v[0]).equal(SIMDFloat4(1.3, 2, 3, 4)));
	CHECK(SIMDFloat4(mat.v[1]).equal(SIMDFloat4(5, 6, 7, 8)));
	CHECK(SIMDFloat4(mat.v[2]).equal(SIMDFloat4(9, 10, 11, 12)));
	CHECK(SIMDFloat4(mat.v[3]).equal(SIMDFloat4(13, 14, 0, -23.4f)));
}

TEST_CASE("SIMDMatrix4 indentify")
{
	SIMDMatrix4 mat = SIMDMatrix4::Identity();

	CHECK(SIMDFloat4(mat.v[0]).equal(SIMDFloat4(1, 0, 0, 0)));
	CHECK(SIMDFloat4(mat.v[1]).equal(SIMDFloat4(0, 1, 0, 0)));
	CHECK(SIMDFloat4(mat.v[2]).equal(SIMDFloat4(0, 0, 1, 0)));
	CHECK(SIMDFloat4(mat.v[3]).equal(SIMDFloat4(0, 0, 0, 1)));
}

TEST_CASE("SIMDMatrix4 + operator")
{
	SIMDMatrix4 mat1(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	SIMDMatrix4 mat2(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);

	SIMDMatrix4 mat3 = mat1 + mat2;

	CHECK(SIMDFloat4(mat3.v[0]).equal(SIMDFloat4(2.3, -3.6, 0, 0.9)));
	CHECK(SIMDFloat4(mat3.v[1]).equal(SIMDFloat4(8.3, 1.6, -1.61, 0.5)));
	CHECK(SIMDFloat4(mat3.v[2]).equal(SIMDFloat4(4.2, -4.2, -5.3, -6.4)));
	CHECK(SIMDFloat4(mat3.v[3]).equal(SIMDFloat4(13.3, -6.8, 0, -0.6)));
}

TEST_CASE("+SIMDMatrix4 operator")
{
	SIMDMatrix4 mat1(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);

	SIMDMatrix4 mat2 = +mat1;
	CHECK(SIMDFloat4(mat2.v[0]).isZero());
	CHECK(SIMDFloat4(mat2.v[1]).equal(SIMDFloat4(2, 1.3, 3.69, 0.6)));
	CHECK(SIMDFloat4(mat2.v[2]).equal(SIMDFloat4(-2.9, -4.3, -3, -6.3)));
	CHECK(SIMDFloat4(mat2.v[3]).equal(SIMDFloat4(0.2, -1.1, 0.6, -0.3)));
}

TEST_CASE("SIMDMatrix4 += operator")
{
	SIMDMatrix4 m1(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	SIMDMatrix4 m2(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);
	SIMDMatrix4 m3(
		1.2, -4.1, 0, 1.2,
		3.5, -0.4, -6.6, 3.4,
		-9.3, .8, -1.8, 9.9,
		-8.5, -9.3, -1.2, 0.6
	);

	m1 += m2 += m3;

	CHECK(SIMDFloat4(m1.v[0]).equal(SIMDFloat4(3.5, -7.7, 0, 2.1)));
	CHECK(SIMDFloat4(m1.v[1]).equal(SIMDFloat4(11.8, 1.2, -8.21, 3.9)));
	CHECK(SIMDFloat4(m1.v[2]).equal(SIMDFloat4(-5.1, -3.4, -7.1, 3.5)));
	CHECK(SIMDFloat4(m1.v[3]).equal(SIMDFloat4(4.8, -16.1, -1.2, 0)));

	CHECK(SIMDFloat4(m2.v[0]).equal(SIMDFloat4(3.5, -7.7, 0, 2.1)));
	CHECK(SIMDFloat4(m2.v[1]).equal(SIMDFloat4(9.8, -0.1, -11.9, 3.3)));
	CHECK(SIMDFloat4(m2.v[2]).equal(SIMDFloat4(-2.2, 0.9, -4.1, 9.8)));
	CHECK(SIMDFloat4(m2.v[3]).equal(SIMDFloat4(4.6, -15, -1.8, 0.3)));
}

TEST_CASE("SIMDMatrix4 - operator")
{
	SIMDMatrix4 m1 = SIMDMatrix4(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	SIMDMatrix4 m2 = SIMDMatrix4(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);

	SIMDMatrix4 m3 = m1 - m2;

	CHECK(SIMDFloat4(m3.v[0]).equal(SIMDFloat4(-2.3, 3.6, 0, -0.9)));
	CHECK(SIMDFloat4(m3.v[1]).equal(SIMDFloat4(-4.3, 1, 8.99, 0.7)));
	CHECK(SIMDFloat4(m3.v[2]).equal(SIMDFloat4(-10, -4.4, -0.7, -6.2)));
	CHECK(SIMDFloat4(m3.v[3]).equal(SIMDFloat4(-12.9, 4.6, 1.2, 0)));
}

TEST_CASE("-SIMDMatrix4 operator")
{
	SIMDMatrix4 mat1(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);

	SIMDMatrix4 mat2 = -mat1;
	CHECK(SIMDFloat4(mat2.v[0]).isZero());
	CHECK(SIMDFloat4(mat2.v[1]).equal(SIMDFloat4(-2, -1.3, -3.69, -0.6)));
	CHECK(SIMDFloat4(mat2.v[2]).equal(SIMDFloat4(2.9, 4.3, 3, 6.3)));
	CHECK(SIMDFloat4(mat2.v[3]).equal(SIMDFloat4(-0.2, 1.1, -0.6, 0.3)));
}

TEST_CASE("SIMDMatrix4 -= operator")
{
	SIMDMatrix4 m1(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	SIMDMatrix4 m2(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);
	SIMDMatrix4 m3(
		1.2, -4.1, 0, 1.2,
		3.5, -0.4, -6.6, 3.4,
		-9.3, .8, -1.8, 9.9,
		-8.5, -9.3, -1.2, 0.6
	);

	m1 -= m2 -= m3;

	CHECK(SIMDFloat4(m1.v[0]).equal(SIMDFloat4(-1.1, -0.5, 0, 0.3)));
	CHECK(SIMDFloat4(m1.v[1]).equal(SIMDFloat4(-0.8, 0.6, 2.39, 4.1)));
	CHECK(SIMDFloat4(m1.v[2]).equal(SIMDFloat4(-19.3, -3.6, -2.5, 3.7)));
	CHECK(SIMDFloat4(m1.v[3]).equal(SIMDFloat4(-21.4, -4.7, 0, 0.6)));

	CHECK(SIMDFloat4(m2.v[0]).equal(SIMDFloat4(1.1, 0.5, 0, -0.3)));
	CHECK(SIMDFloat4(m2.v[1]).equal(SIMDFloat4(2.8, 0.7, 1.3, -3.5)));
	CHECK(SIMDFloat4(m2.v[2]).equal(SIMDFloat4(16.4, -0.7, -0.5, -10)));
	CHECK(SIMDFloat4(m2.v[3]).equal(SIMDFloat4(21.6, 3.6, 0.6, -0.9)));
}

TEST_CASE("SIMDMatrix4 * double operator")
{
	SIMDMatrix4 mat1(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);

	SIMDMatrix4 mat2 = mat1 * 2.3;

	CHECK(SIMDFloat4(mat2.v[0]).equal(SIMDFloat4(0, 1.15, -1.15, -31.05)));
	CHECK(SIMDFloat4(mat2.v[1]).equal(SIMDFloat4(4.6, 2.99, 8.487, 1.38)));
	CHECK(SIMDFloat4(mat2.v[2]).equal(SIMDFloat4(-6.67, -9.89, -6.9, -14.49)));
	CHECK(SIMDFloat4(mat2.v[3]).equal(SIMDFloat4(0.46, -2.53, 1.38, -0.69)));
}

TEST_CASE("double * SIMDMatrix4 operator")
{
	SIMDMatrix4 mat1(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);

	SIMDMatrix4 mat2 = 2.3 * mat1;

	CHECK(SIMDFloat4(mat2.v[0]).equal(SIMDFloat4(0, 1.15, -1.15, -31.05)));
	CHECK(SIMDFloat4(mat2.v[1]).equal(SIMDFloat4(4.6, 2.99, 8.487, 1.38)));
	CHECK(SIMDFloat4(mat2.v[2]).equal(SIMDFloat4(-6.67, -9.89, -6.9, -14.49)));
	CHECK(SIMDFloat4(mat2.v[3]).equal(SIMDFloat4(0.46, -2.53, 1.38, -0.69)));
}

TEST_CASE("Matri4 *= double operator")
{
	SIMDMatrix4 m(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	double k1 = 2.3;
	double k2 = -9.1;

	(m *= k1) *= k2;

	CHECK(SIMDFloat4(m.v[0]).equal(SIMDFloat4(0, -10.465, 10.465, 282.555)));
	CHECK(SIMDFloat4(m.v[1]).equal(SIMDFloat4(-41.86, -27.209, -77.2317, -12.558)));
	CHECK(SIMDFloat4(m.v[2]).equal(SIMDFloat4(60.697, 89.999, 62.79, 131.859)));
	CHECK(SIMDFloat4(m.v[3]).equal(SIMDFloat4(-4.186, 23.023, -12.558, 6.279)));
}

TEST_CASE("SIMDMatrix4 * SIMDMatrix4 operator")
{
	SIMDMatrix4 m1(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);
	SIMDMatrix4 m2(
		1.2, -4.1, 0, 1.2,
		3.5, -0.4, -6.6, 3.4,
		-9.3, .8, -1.8, 9.9,
		-8.5, -9.3, -1.2, 0.6
	);

	SIMDMatrix4 m3 = m1 * m2;

	CHECK(SIMDFloat4(m3.v[0]).equal(SIMDFloat4(-17.49, -16.36, 22.68, -8.94)));
	CHECK(SIMDFloat4(m3.v[1]).equal(SIMDFloat4(58.75, -29.26, 7.68, -43.95)));
	CHECK(SIMDFloat4(m3.v[2]).equal(SIMDFloat4(31.11, -30.06, 3.6, -13.97)));
	CHECK(SIMDFloat4(m3.v[3]).equal(SIMDFloat4(3.9, -49.12, 39.06, -9.78)));

	SIMDMatrix4 m4 = m2 * m1;

	CHECK(SIMDFloat4(m4.v[0]).equal(SIMDFloat4(-7.35, -12.39, 21.01, 1.13)));
	CHECK(SIMDFloat4(m4.v[1]).equal(SIMDFloat4(3.21, -32.76, 15.26, 2.83)));
	CHECK(SIMDFloat4(m4.v[2]).equal(SIMDFloat4(100.56, -22.89, -6.04, -11.24)));
	CHECK(SIMDFloat4(m4.v[3]).equal(SIMDFloat4(-78.8, 24.27, 51.69, -6.78)));
}

TEST_CASE("SIMDMatrix4 *= operator")
{
	SIMDMatrix4 m1(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	SIMDMatrix4 m2(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);
	SIMDMatrix4 m3(
		1.2, -4.1, 0, 1.2,
		3.5, -0.4, -6.6, 3.4,
		-9.3, .8, -1.8, 9.9,
		-8.5, -9.3, -1.2, 0.6
	);

	m1 *= m2 *= m3;

	CHECK(SIMDFloat4(m1.v[0]).equal(SIMDFloat4(-38.83, 663.52, -525.27, 117.04)));
	CHECK(SIMDFloat4(m1.v[1]).equal(SIMDFloat4(158.5309, -211.1514, 92.064, -132.4323)));
	CHECK(SIMDFloat4(m1.v[2]).equal(SIMDFloat4(-319.804, 572.898, -355.674, 318.435)));
	CHECK(SIMDFloat4(m1.v[3]).equal(SIMDFloat4(-50.627, 25.614, -13.47, 41.109)));

	CHECK(SIMDFloat4(m2.v[0]).equal(SIMDFloat4(-17.49, -16.36, 22.68, -8.94)));
	CHECK(SIMDFloat4(m2.v[1]).equal(SIMDFloat4(58.75, -29.26, 7.68, -43.95)));
	CHECK(SIMDFloat4(m2.v[2]).equal(SIMDFloat4(31.11, -30.06, 3.6, -13.97)));
	CHECK(SIMDFloat4(m2.v[3]).equal(SIMDFloat4(3.9, -49.12, 39.06, -9.78)));
}

TEST_CASE("SIMDFloat4 * SIMDMatrix4 operator")
{
	SIMDMatrix4 m(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	SIMDFloat4 f1(1, 2, 3, -4);
	SIMDFloat4 f2 = f1 * m;

	CHECK(SIMDFloat4(f2.m).equal(SIMDFloat4(-5.5, -5.4, -4.52, -30)));
}

TEST_CASE("*= SIMDMatrix4 operator")
{
	SIMDMatrix4 m(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	SIMDFloat4 f1(1, 2, 3, -4);
	SIMDFloat4 f2 = f1 *= m;

	CHECK(SIMDFloat4(f2.m).equal(SIMDFloat4(-5.5, -5.4, -4.52, -30)));
}

TEST_CASE("SIMDMatrix4 / float operator")
{
	SIMDMatrix4 mat1(
		1.3, 2, 3, 4,
		-5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 0, -23.4f
	);

	float k = -2.5;
	SIMDMatrix4 mat2 = mat1 / k;

	CHECK(SIMDFloat4(mat2.v[0]).equal(SIMDFloat4(1.3 / -2.5, 2 / -2.5, 3 / -2.5, 4 / -2.5)));
	CHECK(SIMDFloat4(mat2.v[1]).equal(SIMDFloat4(-5 / -2.5, 6 / -2.5, 7 / -2.5, 8 / -2.5)));
	CHECK(SIMDFloat4(mat2.v[2]).equal(SIMDFloat4(9 / -2.5, 10 / -2.5, 11 / -2.5, 12 / -2.5)));
	CHECK(SIMDFloat4(mat2.v[3]).equal(SIMDFloat4(13 / -2.5, 14 / -2.5, 0, -23.4 / -2.5)));
}

TEST_CASE("SIMDMatrix4 /= float operator")
{
	SIMDMatrix4 mat(
		1.3, 2, 3, 4,
		-5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 0, -23.4f
	);

	float k1 = -2.5;
	float k2 = 0.8;
	(mat /= k1) /= k2;

	CHECK(SIMDFloat4(mat.v[0]).equal(SIMDFloat4(1.3 / -2.5 / 0.8, 2 / -2.5 / 0.8, 3 / -2.5 / 0.8, 4 / -2.5 / 0.8)));
	CHECK(SIMDFloat4(mat.v[1]).equal(SIMDFloat4(-5 / -2.5 / 0.8, 6 / -2.5 / 0.8, 7 / -2.5 / 0.8, 8 / -2.5 / 0.8)));
	CHECK(SIMDFloat4(mat.v[2]).equal(SIMDFloat4(9 / -2.5 / 0.8, 10 / -2.5 / 0.8, 11 / -2.5 / 0.8, 12 / -2.5 / 0.8)));
	CHECK(SIMDFloat4(mat.v[3]).equal(SIMDFloat4(13 / -2.5 / 0.8, 14 / -2.5 / 0.8, 0, -23.4 / -2.5 / 0.8)));
}

TEST_CASE("SIMDMatrix4 det calc")
{
	SIMDMatrix4 mat(
		-2, 1, 1, 2,
		5, 1, 9.8, 4,
		2, 0, 1, 0,
		1, 3, 2, 1.6
	);
	CHECK(mat.det() == doctest::Approx(-28.64).epsilon(0.01));
}

TEST_CASE("storeValue() checked")
{
	SIMDMatrix4 mat{};
	mat.v[0] = _mm_set_ps(4, 3, 2, 1);
	mat.v[1] = _mm_set_ps(-1, -2, -3, -4);
	mat.v[2] = _mm_set_ps(0, -.5, 1.5, -2);
	mat.v[3] = _mm_set_ps(-2, 2.5, -3, 3.5);

	CHECK(SIMDFloat4(mat.v[0]).equal(SIMDFloat4(1, 2, 3, 4)));
	CHECK(SIMDFloat4(mat.v[1]).equal(SIMDFloat4(-4, -3, -2, -1)));
	CHECK(SIMDFloat4(mat.v[2]).equal(SIMDFloat4(-2, 1.5, -0.5, 0)));
	CHECK(SIMDFloat4(mat.v[3]).equal(SIMDFloat4(3.5, -3, 2.5, -2)));
}