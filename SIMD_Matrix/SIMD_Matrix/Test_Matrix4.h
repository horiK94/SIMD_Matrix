#pragma once
#include "Matrix4.h"
#include "ThirdParty/doctest/doctest.h"

TEST_CASE("Matrix4 zero matrix construct")
{
	Matrix4 zeroMat = Matrix4();
	CHECK(zeroMat.m[0][0] == 0);
	CHECK(zeroMat.m[0][1] == 0);
	CHECK(zeroMat.m[0][2] == 0);
	CHECK(zeroMat.m[0][3] == 0);

	CHECK(zeroMat.m[1][0] == 0);
	CHECK(zeroMat.m[1][1] == 0);
	CHECK(zeroMat.m[1][2] == 0);
	CHECK(zeroMat.m[1][3] == 0);

	CHECK(zeroMat.m[2][0] == 0);
	CHECK(zeroMat.m[2][1] == 0);
	CHECK(zeroMat.m[2][2] == 0);
	CHECK(zeroMat.m[2][3] == 0);

	CHECK(zeroMat.m[3][0] == 0);
	CHECK(zeroMat.m[3][1] == 0);
	CHECK(zeroMat.m[3][2] == 0);
	CHECK(zeroMat.m[3][3] == 0);
}

TEST_CASE("Matrix4 each element construct")
{
	Matrix4 mat(
		1.3, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 0, -23.4f
	);

	CHECK(mat.m[0][0] == doctest::Approx(1.3).epsilon(0.01));
	CHECK(mat.m[0][1] == doctest::Approx(2).epsilon(0.01));
	CHECK(mat.m[0][2] == doctest::Approx(3).epsilon(0.01));
	CHECK(mat.m[0][3] == doctest::Approx(4).epsilon(0.01));

	CHECK(mat.m[1][0] == doctest::Approx(5).epsilon(0.01));
	CHECK(mat.m[1][1] == doctest::Approx(6).epsilon(0.01));
	CHECK(mat.m[1][2] == doctest::Approx(7).epsilon(0.01));
	CHECK(mat.m[1][3] == doctest::Approx(8).epsilon(0.01));

	CHECK(mat.m[2][0] == doctest::Approx(9).epsilon(0.01));
	CHECK(mat.m[2][1] == doctest::Approx(10).epsilon(0.01));
	CHECK(mat.m[2][2] == doctest::Approx(11).epsilon(0.01));
	CHECK(mat.m[2][3] == doctest::Approx(12).epsilon(0.01));

	CHECK(mat.m[3][0] == doctest::Approx(13).epsilon(0.01));
	CHECK(mat.m[3][1] == doctest::Approx(14).epsilon(0.01));
	CHECK(mat.m[3][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[3][3] == doctest::Approx(-23.4f).epsilon(0.01));
}

TEST_CASE("Matrix4 double array construct")
{
	float elem[4][4] = {
		{1.3, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 0, -23.4f}
	};

	Matrix4 mat(elem);

	CHECK(mat.m[0][0] == doctest::Approx(1.3).epsilon(0.01));
	CHECK(mat.m[0][1] == doctest::Approx(2).epsilon(0.01));
	CHECK(mat.m[0][2] == doctest::Approx(3).epsilon(0.01));
	CHECK(mat.m[0][3] == doctest::Approx(4).epsilon(0.01));

	CHECK(mat.m[1][0] == doctest::Approx(5).epsilon(0.01));
	CHECK(mat.m[1][1] == doctest::Approx(6).epsilon(0.01));
	CHECK(mat.m[1][2] == doctest::Approx(7).epsilon(0.01));
	CHECK(mat.m[1][3] == doctest::Approx(8).epsilon(0.01));

	CHECK(mat.m[2][0] == doctest::Approx(9).epsilon(0.01));
	CHECK(mat.m[2][1] == doctest::Approx(10).epsilon(0.01));
	CHECK(mat.m[2][2] == doctest::Approx(11).epsilon(0.01));
	CHECK(mat.m[2][3] == doctest::Approx(12).epsilon(0.01));

	CHECK(mat.m[3][0] == doctest::Approx(13).epsilon(0.01));
	CHECK(mat.m[3][1] == doctest::Approx(14).epsilon(0.01));
	CHECK(mat.m[3][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[3][3] == doctest::Approx(-23.4f).epsilon(0.01));
}

TEST_CASE("Matrix4 each Float4 construct")
{
	Matrix4 mat(Float4(1.3, 2, 3, 4), Float4(5, 6, 7, 8), Float4(9, 10, 11, 12), Float4(13, 14, 0, -23.4f));

	CHECK(mat.m[0][0] == doctest::Approx(1.3).epsilon(0.01));
	CHECK(mat.m[1][0] == doctest::Approx(2).epsilon(0.01));
	CHECK(mat.m[2][0] == doctest::Approx(3).epsilon(0.01));
	CHECK(mat.m[3][0] == doctest::Approx(4).epsilon(0.01));

	CHECK(mat.m[0][1] == doctest::Approx(5).epsilon(0.01));
	CHECK(mat.m[1][1] == doctest::Approx(6).epsilon(0.01));
	CHECK(mat.m[2][1] == doctest::Approx(7).epsilon(0.01));
	CHECK(mat.m[3][1] == doctest::Approx(8).epsilon(0.01));

	CHECK(mat.m[0][2] == doctest::Approx(9).epsilon(0.01));
	CHECK(mat.m[1][2] == doctest::Approx(10).epsilon(0.01));
	CHECK(mat.m[2][2] == doctest::Approx(11).epsilon(0.01));
	CHECK(mat.m[3][2] == doctest::Approx(12).epsilon(0.01));

	CHECK(mat.m[0][3] == doctest::Approx(13).epsilon(0.01));
	CHECK(mat.m[1][3] == doctest::Approx(14).epsilon(0.01));
	CHECK(mat.m[2][3] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[3][3] == doctest::Approx(-23.4f).epsilon(0.01));
}

TEST_CASE("Matrix4 indentify")
{
	Matrix4 mat = Matrix4::Identity();

	CHECK(mat.m[0][0] == doctest::Approx(1).epsilon(0.01));
	CHECK(mat.m[0][1] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[0][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[0][3] == doctest::Approx(0).epsilon(0.01));

	CHECK(mat.m[1][0] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[1][1] == doctest::Approx(1).epsilon(0.01));
	CHECK(mat.m[1][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[1][3] == doctest::Approx(0).epsilon(0.01));

	CHECK(mat.m[2][0] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[2][1] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[2][2] == doctest::Approx(1).epsilon(0.01));
	CHECK(mat.m[2][3] == doctest::Approx(0).epsilon(0.01));

	CHECK(mat.m[3][0] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[3][1] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[3][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[3][3] == doctest::Approx(1).epsilon(0.01));
}

TEST_CASE("Matrix4 + operator")
{
	Matrix4 mat1(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	Matrix4 mat2(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);

	Matrix4 mat3 = mat1 + mat2;
	CHECK(mat3.m[0][0] == doctest::Approx(2.3).epsilon(0.01));
	CHECK(mat3.m[0][1] == doctest::Approx(-3.6).epsilon(0.01));
	CHECK(mat3.m[0][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat3.m[0][3] == doctest::Approx(0.9).epsilon(0.01));

	CHECK(mat3.m[1][0] == doctest::Approx(8.3).epsilon(0.01));
	CHECK(mat3.m[1][1] == doctest::Approx(1.6).epsilon(0.01));
	CHECK(mat3.m[1][2] == doctest::Approx(-1.61).epsilon(0.01));
	CHECK(mat3.m[1][3] == doctest::Approx(0.5).epsilon(0.01));

	CHECK(mat3.m[2][0] == doctest::Approx(4.2).epsilon(0.01));
	CHECK(mat3.m[2][1] == doctest::Approx(-4.2).epsilon(0.01));
	CHECK(mat3.m[2][2] == doctest::Approx(-5.3).epsilon(0.01));
	CHECK(mat3.m[2][3] == doctest::Approx(-6.4).epsilon(0.01));

	CHECK(mat3.m[3][0] == doctest::Approx(13.3).epsilon(0.01));
	CHECK(mat3.m[3][1] == doctest::Approx(-6.8).epsilon(0.01));
	CHECK(mat3.m[3][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat3.m[3][3] == doctest::Approx(-0.6).epsilon(0.01));
}

TEST_CASE("+Matrix4 operator")
{
	Matrix4 mat1(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);

	Matrix4 mat2 = +mat1;
	CHECK(mat2.m[0][0] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat2.m[0][1] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat2.m[0][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat2.m[0][3] == doctest::Approx(0).epsilon(0.01));

	CHECK(mat2.m[1][0] == doctest::Approx(2).epsilon(0.01));
	CHECK(mat2.m[1][1] == doctest::Approx(1.3).epsilon(0.01));
	CHECK(mat2.m[1][2] == doctest::Approx(3.69).epsilon(0.01));
	CHECK(mat2.m[1][3] == doctest::Approx(0.6).epsilon(0.01));

	CHECK(mat2.m[2][0] == doctest::Approx(-2.9).epsilon(0.01));
	CHECK(mat2.m[2][1] == doctest::Approx(-4.3).epsilon(0.01));
	CHECK(mat2.m[2][2] == doctest::Approx(-3).epsilon(0.01));
	CHECK(mat2.m[2][3] == doctest::Approx(-6.3).epsilon(0.01));

	CHECK(mat2.m[3][0] == doctest::Approx(0.2).epsilon(0.01));
	CHECK(mat2.m[3][1] == doctest::Approx(-1.1).epsilon(0.01));
	CHECK(mat2.m[3][2] == doctest::Approx(0.6).epsilon(0.01));
	CHECK(mat2.m[3][3] == doctest::Approx(-0.3).epsilon(0.01));
}

TEST_CASE("Matrix4 += operator")
{
	Matrix4 m1(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	Matrix4 m2(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);
	Matrix4 m3(
		1.2, -4.1, 0, 1.2,
		3.5, -0.4, -6.6, 3.4,
		-9.3, .8, -1.8, 9.9,
		-8.5, -9.3, -1.2, 0.6
	);

	m1 += m2 += m3;

	CHECK(m1.m[0][0] == doctest::Approx(3.5).epsilon(0.01));
	CHECK(m1.m[0][1] == doctest::Approx(-7.7).epsilon(0.01));
	CHECK(m1.m[0][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(m1.m[0][3] == doctest::Approx(2.1).epsilon(0.01));

	CHECK(m1.m[1][0] == doctest::Approx(11.8).epsilon(0.01));
	CHECK(m1.m[1][1] == doctest::Approx(1.2).epsilon(0.01));
	CHECK(m1.m[1][2] == doctest::Approx(-8.21).epsilon(0.01));
	CHECK(m1.m[1][3] == doctest::Approx(3.9).epsilon(0.01));

	CHECK(m1.m[2][0] == doctest::Approx(-5.1).epsilon(0.01));
	CHECK(m1.m[2][1] == doctest::Approx(-3.4).epsilon(0.01));
	CHECK(m1.m[2][2] == doctest::Approx(-7.1).epsilon(0.01));
	CHECK(m1.m[2][3] == doctest::Approx(3.5).epsilon(0.01));

	CHECK(m1.m[3][0] == doctest::Approx(4.8).epsilon(0.01));
	CHECK(m1.m[3][1] == doctest::Approx(-16.1).epsilon(0.01));
	CHECK(m1.m[3][2] == doctest::Approx(-1.2).epsilon(0.01));
	CHECK(m1.m[3][3] == doctest::Approx(0).epsilon(0.01));

	CHECK(m2.m[0][0] == doctest::Approx(3.5).epsilon(0.01));
	CHECK(m2.m[0][1] == doctest::Approx(-7.7).epsilon(0.01));
	CHECK(m2.m[0][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(m2.m[0][3] == doctest::Approx(2.1).epsilon(0.01));

	CHECK(m2.m[1][0] == doctest::Approx(9.8).epsilon(0.01));
	CHECK(m2.m[1][1] == doctest::Approx(-0.1).epsilon(0.01));
	CHECK(m2.m[1][2] == doctest::Approx(-11.9).epsilon(0.01));
	CHECK(m2.m[1][3] == doctest::Approx(3.3).epsilon(0.01));

	CHECK(m2.m[2][0] == doctest::Approx(-2.2).epsilon(0.01));
	CHECK(m2.m[2][1] == doctest::Approx(0.9).epsilon(0.01));
	CHECK(m2.m[2][2] == doctest::Approx(-4.1).epsilon(0.01));
	CHECK(m2.m[2][3] == doctest::Approx(9.8).epsilon(0.01));

	CHECK(m2.m[3][0] == doctest::Approx(4.6).epsilon(0.01));
	CHECK(m2.m[3][1] == doctest::Approx(-15).epsilon(0.01));
	CHECK(m2.m[3][2] == doctest::Approx(-1.8).epsilon(0.01));
	CHECK(m2.m[3][3] == doctest::Approx(0.3).epsilon(0.01));
}

TEST_CASE("Matrix4 - operator")
{
	Matrix4 m1 = Matrix4(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	Matrix4 m2 = Matrix4(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);

	Matrix4 m3 = m1 - m2;
	CHECK(m3.m[0][0] == doctest::Approx(-2.3).epsilon(0.01));
	CHECK(m3.m[0][1] == doctest::Approx(3.6).epsilon(0.01));
	CHECK(m3.m[0][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(m3.m[0][3] == doctest::Approx(-0.9).epsilon(0.01));

	CHECK(m3.m[1][0] == doctest::Approx(-4.3).epsilon(0.01));
	CHECK(m3.m[1][1] == doctest::Approx(1).epsilon(0.01));
	CHECK(m3.m[1][2] == doctest::Approx(8.99).epsilon(0.01));
	CHECK(m3.m[1][3] == doctest::Approx(0.7).epsilon(0.01));

	CHECK(m3.m[2][0] == doctest::Approx(-10).epsilon(0.01));
	CHECK(m3.m[2][1] == doctest::Approx(-4.4).epsilon(0.01));
	CHECK(m3.m[2][2] == doctest::Approx(-0.7).epsilon(0.01));
	CHECK(m3.m[2][3] == doctest::Approx(-6.2).epsilon(0.01));

	CHECK(m3.m[3][0] == doctest::Approx(-12.9).epsilon(0.01));
	CHECK(m3.m[3][1] == doctest::Approx(4.6).epsilon(0.01));
	CHECK(m3.m[3][2] == doctest::Approx(1.2).epsilon(0.01));
	CHECK(m3.m[3][3] == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("-Matrix4 operator")
{
	Matrix4 mat1(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);

	Matrix4 mat2 = -mat1;
	CHECK(mat2.m[0][0] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat2.m[0][1] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat2.m[0][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat2.m[0][3] == doctest::Approx(0).epsilon(0.01));

	CHECK(mat2.m[1][0] == doctest::Approx(-2).epsilon(0.01));
	CHECK(mat2.m[1][1] == doctest::Approx(-1.3).epsilon(0.01));
	CHECK(mat2.m[1][2] == doctest::Approx(-3.69).epsilon(0.01));
	CHECK(mat2.m[1][3] == doctest::Approx(-0.6).epsilon(0.01));

	CHECK(mat2.m[2][0] == doctest::Approx(2.9).epsilon(0.01));
	CHECK(mat2.m[2][1] == doctest::Approx(4.3).epsilon(0.01));
	CHECK(mat2.m[2][2] == doctest::Approx(3).epsilon(0.01));
	CHECK(mat2.m[2][3] == doctest::Approx(6.3).epsilon(0.01));

	CHECK(mat2.m[3][0] == doctest::Approx(-0.2).epsilon(0.01));
	CHECK(mat2.m[3][1] == doctest::Approx(1.1).epsilon(0.01));
	CHECK(mat2.m[3][2] == doctest::Approx(-0.6).epsilon(0.01));
	CHECK(mat2.m[3][3] == doctest::Approx(0.3).epsilon(0.01));
}

TEST_CASE("Matrix4 -= operator")
{
	Matrix4 m1(
		0, 0, 0, 0,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	Matrix4 m2(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);
	Matrix4 m3(
		1.2, -4.1, 0, 1.2,
		3.5, -0.4, -6.6, 3.4,
		-9.3, .8, -1.8, 9.9,
		-8.5, -9.3, -1.2, 0.6
	);

	m1 -= m2 -= m3;

	CHECK(m1.m[0][0] == doctest::Approx(-1.1).epsilon(0.01));
	CHECK(m1.m[0][1] == doctest::Approx(-0.5).epsilon(0.01));
	CHECK(m1.m[0][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(m1.m[0][3] == doctest::Approx(0.3).epsilon(0.01));

	CHECK(m1.m[1][0] == doctest::Approx(-0.8).epsilon(0.01));
	CHECK(m1.m[1][1] == doctest::Approx(0.6).epsilon(0.01));
	CHECK(m1.m[1][2] == doctest::Approx(2.39).epsilon(0.01));
	CHECK(m1.m[1][3] == doctest::Approx(4.1).epsilon(0.01));

	CHECK(m1.m[2][0] == doctest::Approx(-19.3).epsilon(0.01));
	CHECK(m1.m[2][1] == doctest::Approx(-3.6).epsilon(0.01));
	CHECK(m1.m[2][2] == doctest::Approx(-2.5).epsilon(0.01));
	CHECK(m1.m[2][3] == doctest::Approx(3.7).epsilon(0.01));

	CHECK(m1.m[3][0] == doctest::Approx(-21.4).epsilon(0.01));
	CHECK(m1.m[3][1] == doctest::Approx(-4.7).epsilon(0.01));
	CHECK(m1.m[3][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(m1.m[3][3] == doctest::Approx(0.6).epsilon(0.01));
}

TEST_CASE("Matrix4 * double operator")
{
	Matrix4 mat1(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);

	Matrix4 mat2 = mat1 * 2.3;
	CHECK(mat2.m[0][0] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat2.m[0][1] == doctest::Approx(1.15).epsilon(0.01));
	CHECK(mat2.m[0][2] == doctest::Approx(-1.15).epsilon(0.01));
	CHECK(mat2.m[0][3] == doctest::Approx(-31.05).epsilon(0.01));

	CHECK(mat2.m[1][0] == doctest::Approx(4.6).epsilon(0.01));
	CHECK(mat2.m[1][1] == doctest::Approx(2.99).epsilon(0.01));
	CHECK(mat2.m[1][2] == doctest::Approx(8.487).epsilon(0.01));
	CHECK(mat2.m[1][3] == doctest::Approx(1.38).epsilon(0.01));

	CHECK(mat2.m[2][0] == doctest::Approx(-6.67).epsilon(0.01));
	CHECK(mat2.m[2][1] == doctest::Approx(-9.89).epsilon(0.01));
	CHECK(mat2.m[2][2] == doctest::Approx(-6.9).epsilon(0.01));
	CHECK(mat2.m[2][3] == doctest::Approx(-14.49).epsilon(0.01));

	CHECK(mat2.m[3][0] == doctest::Approx(0.46).epsilon(0.01));
	CHECK(mat2.m[3][1] == doctest::Approx(-2.53).epsilon(0.01));
	CHECK(mat2.m[3][2] == doctest::Approx(1.38).epsilon(0.01));
	CHECK(mat2.m[3][3] == doctest::Approx(-0.69).epsilon(0.01));
}

TEST_CASE("double * Matrix4 operator")
{
	Matrix4 mat1(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);

	Matrix4 mat2 = 2.3 * mat1;
	CHECK(mat2.m[0][0] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat2.m[0][1] == doctest::Approx(1.15).epsilon(0.01));
	CHECK(mat2.m[0][2] == doctest::Approx(-1.15).epsilon(0.01));
	CHECK(mat2.m[0][3] == doctest::Approx(-31.05).epsilon(0.01));

	CHECK(mat2.m[1][0] == doctest::Approx(4.6).epsilon(0.01));
	CHECK(mat2.m[1][1] == doctest::Approx(2.99).epsilon(0.01));
	CHECK(mat2.m[1][2] == doctest::Approx(8.487).epsilon(0.01));
	CHECK(mat2.m[1][3] == doctest::Approx(1.38).epsilon(0.01));

	CHECK(mat2.m[2][0] == doctest::Approx(-6.67).epsilon(0.01));
	CHECK(mat2.m[2][1] == doctest::Approx(-9.89).epsilon(0.01));
	CHECK(mat2.m[2][2] == doctest::Approx(-6.9).epsilon(0.01));
	CHECK(mat2.m[2][3] == doctest::Approx(-14.49).epsilon(0.01));

	CHECK(mat2.m[3][0] == doctest::Approx(0.46).epsilon(0.01));
	CHECK(mat2.m[3][1] == doctest::Approx(-2.53).epsilon(0.01));
	CHECK(mat2.m[3][2] == doctest::Approx(1.38).epsilon(0.01));
	CHECK(mat2.m[3][3] == doctest::Approx(-0.69).epsilon(0.01));
}

TEST_CASE("Matri4 *= double operator")
{
	Matrix4 m(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	double k1 = 2.3;
	double k2 = -9.1;

	(m *= k1) *= k2;

	CHECK(m.m[0][0] == doctest::Approx(0).epsilon(0.01));
	CHECK(m.m[0][1] == doctest::Approx(-10.465).epsilon(0.01));
	CHECK(m.m[0][2] == doctest::Approx(10.465).epsilon(0.01));
	CHECK(m.m[0][3] == doctest::Approx(282.555).epsilon(0.01));

	CHECK(m.m[1][0] == doctest::Approx(-41.86).epsilon(0.01));
	CHECK(m.m[1][1] == doctest::Approx(-27.209).epsilon(0.01));
	CHECK(m.m[1][2] == doctest::Approx(-77.2317).epsilon(0.01));
	CHECK(m.m[1][3] == doctest::Approx(-12.558).epsilon(0.01));

	CHECK(m.m[2][0] == doctest::Approx(60.697).epsilon(0.01));
	CHECK(m.m[2][1] == doctest::Approx(89.999).epsilon(0.01));
	CHECK(m.m[2][2] == doctest::Approx(62.79).epsilon(0.01));
	CHECK(m.m[2][3] == doctest::Approx(131.859).epsilon(0.01));

	CHECK(m.m[3][0] == doctest::Approx(-4.186).epsilon(0.01));
	CHECK(m.m[3][1] == doctest::Approx(23.023).epsilon(0.01));
	CHECK(m.m[3][2] == doctest::Approx(-12.558).epsilon(0.01));
	CHECK(m.m[3][3] == doctest::Approx(6.279).epsilon(0.01));
}

TEST_CASE("Matrix4 * Matrix4 operator")
{
	Matrix4 m1(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);
	Matrix4 m2(
		1.2, -4.1, 0, 1.2,
		3.5, -0.4, -6.6, 3.4,
		-9.3, .8, -1.8, 9.9,
		-8.5, -9.3, -1.2, 0.6
	);

	Matrix4 m3 = m1 * m2;

	CHECK(m3.m[0][0] == doctest::Approx(-17.49).epsilon(0.01));
	CHECK(m3.m[0][1] == doctest::Approx(-16.36).epsilon(0.01));
	CHECK(m3.m[0][2] == doctest::Approx(22.68).epsilon(0.01));
	CHECK(m3.m[0][3] == doctest::Approx(-8.94).epsilon(0.01));

	CHECK(m3.m[1][0] == doctest::Approx(58.75).epsilon(0.01));
	CHECK(m3.m[1][1] == doctest::Approx(-29.26).epsilon(0.01));
	CHECK(m3.m[1][2] == doctest::Approx(7.68).epsilon(0.01));
	CHECK(m3.m[1][3] == doctest::Approx(-43.95).epsilon(0.01));

	CHECK(m3.m[2][0] == doctest::Approx(31.11).epsilon(0.01));
	CHECK(m3.m[2][1] == doctest::Approx(-30.06).epsilon(0.01));
	CHECK(m3.m[2][2] == doctest::Approx(3.6).epsilon(0.01));
	CHECK(m3.m[2][3] == doctest::Approx(-13.97).epsilon(0.01));

	CHECK(m3.m[3][0] == doctest::Approx(3.9).epsilon(0.01));
	CHECK(m3.m[3][1] == doctest::Approx(-49.12).epsilon(0.01));
	CHECK(m3.m[3][2] == doctest::Approx(39.06).epsilon(0.01));
	CHECK(m3.m[3][3] == doctest::Approx(-9.78).epsilon(0.01));

	Matrix4 m4 = m2 * m1;

	CHECK(m4.m[0][0] == doctest::Approx(-7.35).epsilon(0.01));
	CHECK(m4.m[0][1] == doctest::Approx(-12.39).epsilon(0.01));
	CHECK(m4.m[0][2] == doctest::Approx(21.01).epsilon(0.01));
	CHECK(m4.m[0][3] == doctest::Approx(1.13).epsilon(0.01));

	CHECK(m4.m[1][0] == doctest::Approx(3.21).epsilon(0.01));
	CHECK(m4.m[1][1] == doctest::Approx(-32.76).epsilon(0.01));
	CHECK(m4.m[1][2] == doctest::Approx(15.26).epsilon(0.01));
	CHECK(m4.m[1][3] == doctest::Approx(2.83).epsilon(0.01));

	CHECK(m4.m[2][0] == doctest::Approx(100.56).epsilon(0.01));
	CHECK(m4.m[2][1] == doctest::Approx(-22.89).epsilon(0.01));
	CHECK(m4.m[2][2] == doctest::Approx(-6.04).epsilon(0.01));
	CHECK(m4.m[2][3] == doctest::Approx(-11.24).epsilon(0.01));

	CHECK(m4.m[3][0] == doctest::Approx(-78.8).epsilon(0.01));
	CHECK(m4.m[3][1] == doctest::Approx(24.27).epsilon(0.01));
	CHECK(m4.m[3][2] == doctest::Approx(51.69).epsilon(0.01));
	CHECK(m4.m[3][3] == doctest::Approx(-6.78).epsilon(0.01));
}

TEST_CASE("Matrix4 *= operator")
{
	Matrix4 m1(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	Matrix4 m2(
		2.3, -3.6, 0, 0.9,
		6.3, 0.3, -5.3, -0.1,
		7.1, 0.1, -2.3, -0.1,
		13.1, -5.7, -0.6, -0.3
	);
	Matrix4 m3(
		1.2, -4.1, 0, 1.2,
		3.5, -0.4, -6.6, 3.4,
		-9.3, .8, -1.8, 9.9,
		-8.5, -9.3, -1.2, 0.6
	);

	m1 *= m2 *= m3;

	CHECK(m1.m[0][0] == doctest::Approx(-38.83).epsilon(0.01));
	CHECK(m1.m[0][1] == doctest::Approx(663.52).epsilon(0.01));
	CHECK(m1.m[0][2] == doctest::Approx(-525.27).epsilon(0.01));
	CHECK(m1.m[0][3] == doctest::Approx(117.04).epsilon(0.01));

	CHECK(m1.m[1][0] == doctest::Approx(158.5309).epsilon(0.01));
	CHECK(m1.m[1][1] == doctest::Approx(-211.1514).epsilon(0.01));
	CHECK(m1.m[1][2] == doctest::Approx(92.064).epsilon(0.01));
	CHECK(m1.m[1][3] == doctest::Approx(-132.4323).epsilon(0.01));

	CHECK(m1.m[2][0] == doctest::Approx(-319.804).epsilon(0.01));
	CHECK(m1.m[2][1] == doctest::Approx(572.898).epsilon(0.01));
	CHECK(m1.m[2][2] == doctest::Approx(-355.674).epsilon(0.01));
	CHECK(m1.m[2][3] == doctest::Approx(318.435).epsilon(0.01));

	CHECK(m1.m[3][0] == doctest::Approx(-50.627).epsilon(0.01));
	CHECK(m1.m[3][1] == doctest::Approx(25.614).epsilon(0.01));
	CHECK(m1.m[3][2] == doctest::Approx(-13.47).epsilon(0.01));
	CHECK(m1.m[3][3] == doctest::Approx(41.109).epsilon(0.01));


	CHECK(m2.m[0][0] == doctest::Approx(-17.49).epsilon(0.01));
	CHECK(m2.m[0][1] == doctest::Approx(-16.36).epsilon(0.01));
	CHECK(m2.m[0][2] == doctest::Approx(22.68).epsilon(0.01));
	CHECK(m2.m[0][3] == doctest::Approx(-8.94).epsilon(0.01));

	CHECK(m2.m[1][0] == doctest::Approx(58.75).epsilon(0.01));
	CHECK(m2.m[1][1] == doctest::Approx(-29.26).epsilon(0.01));
	CHECK(m2.m[1][2] == doctest::Approx(7.68).epsilon(0.01));
	CHECK(m2.m[1][3] == doctest::Approx(-43.95).epsilon(0.01));

	CHECK(m2.m[2][0] == doctest::Approx(31.11).epsilon(0.01));
	CHECK(m2.m[2][1] == doctest::Approx(-30.06).epsilon(0.01));
	CHECK(m2.m[2][2] == doctest::Approx(3.6).epsilon(0.01));
	CHECK(m2.m[2][3] == doctest::Approx(-13.97).epsilon(0.01));

	CHECK(m2.m[3][0] == doctest::Approx(3.9).epsilon(0.01));
	CHECK(m2.m[3][1] == doctest::Approx(-49.12).epsilon(0.01));
	CHECK(m2.m[3][2] == doctest::Approx(39.06).epsilon(0.01));
	CHECK(m2.m[3][3] == doctest::Approx(-9.78).epsilon(0.01));
}

TEST_CASE("Matrix4 * Float4 operator")
{
	Matrix4 m(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	Float4 f1(1, 2, 3, -4);
	Float4 f2 = m * f1;

	CHECK(f2.x == doctest::Approx(53.5).epsilon(0.01));
	CHECK(f2.y == doctest::Approx(13.27).epsilon(0.01));
	CHECK(f2.z == doctest::Approx(4.7).epsilon(0.01));
	CHECK(f2.w == doctest::Approx(1).epsilon(0.01));
}

TEST_CASE("*= Float4 operator")
{
	Matrix4 m(
		0, 0.5, -0.5, -13.5,
		2, 1.3, 3.69, 0.6,
		-2.9, -4.3, -3, -6.3,
		0.2, -1.1, 0.6, -0.3
	);
	Float4 f1(1, 2, 3, -4);
	Float4 f2 = m *= f1;

	CHECK(f2.x == doctest::Approx(53.5).epsilon(0.01));
	CHECK(f2.y == doctest::Approx(13.27).epsilon(0.01));
	CHECK(f2.z == doctest::Approx(4.7).epsilon(0.01));
	CHECK(f2.w == doctest::Approx(1).epsilon(0.01));
}

TEST_CASE("Matrix4 / float operator")
{
	Matrix4 mat1(
		1.3, 2, 3, 4,
		-5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 0, -23.4f
	);

	float k = -2.5;
	Matrix4 mat2 = mat1 / k;

	CHECK(mat2.m[0][0] == doctest::Approx(1.3 / -2.5).epsilon(0.01));
	CHECK(mat2.m[0][1] == doctest::Approx(2 / -2.5).epsilon(0.01));
	CHECK(mat2.m[0][2] == doctest::Approx(3 / -2.5).epsilon(0.01));
	CHECK(mat2.m[0][3] == doctest::Approx(4 / -2.5).epsilon(0.01));

	CHECK(mat2.m[1][0] == doctest::Approx(-5 / -2.5).epsilon(0.01));
	CHECK(mat2.m[1][1] == doctest::Approx(6 / -2.5).epsilon(0.01));
	CHECK(mat2.m[1][2] == doctest::Approx(7 / -2.5).epsilon(0.01));
	CHECK(mat2.m[1][3] == doctest::Approx(8 / -2.5).epsilon(0.01));

	CHECK(mat2.m[2][0] == doctest::Approx(9 / -2.5).epsilon(0.01));
	CHECK(mat2.m[2][1] == doctest::Approx(10 / -2.5).epsilon(0.01));
	CHECK(mat2.m[2][2] == doctest::Approx(11 / -2.5).epsilon(0.01));
	CHECK(mat2.m[2][3] == doctest::Approx(12 / -2.5).epsilon(0.01));

	CHECK(mat2.m[3][0] == doctest::Approx(13 / -2.5).epsilon(0.01));
	CHECK(mat2.m[3][1] == doctest::Approx(14 / -2.5).epsilon(0.01));
	CHECK(mat2.m[3][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat2.m[3][3] == doctest::Approx(-23.4 / -2.5).epsilon(0.01));
}

TEST_CASE("Matrix4 / float operator")
{
	Matrix4 mat(
		1.3, 2, 3, 4,
		-5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 0, -23.4f
	);

	float k1 = -2.5;
	float k2 = 0.8;
	(mat /= k1) /= k2;

	CHECK(mat.m[0][0] == doctest::Approx(1.3 / -2.5 / 0.8).epsilon(0.01));
	CHECK(mat.m[0][1] == doctest::Approx(2 / -2.5 / 0.8).epsilon(0.01));
	CHECK(mat.m[0][2] == doctest::Approx(3 / -2.5 / 0.8).epsilon(0.01));
	CHECK(mat.m[0][3] == doctest::Approx(4 / -2.5 / 0.8).epsilon(0.01));

	CHECK(mat.m[1][0] == doctest::Approx(-5 / -2.5 / 0.8).epsilon(0.01));
	CHECK(mat.m[1][1] == doctest::Approx(6 / -2.5 / 0.8).epsilon(0.01));
	CHECK(mat.m[1][2] == doctest::Approx(7 / -2.5 / 0.8).epsilon(0.01));
	CHECK(mat.m[1][3] == doctest::Approx(8 / -2.5 / 0.8).epsilon(0.01));

	CHECK(mat.m[2][0] == doctest::Approx(9 / -2.5 / 0.8).epsilon(0.01));
	CHECK(mat.m[2][1] == doctest::Approx(10 / -2.5 / 0.8).epsilon(0.01));
	CHECK(mat.m[2][2] == doctest::Approx(11 / -2.5 / 0.8).epsilon(0.01));
	CHECK(mat.m[2][3] == doctest::Approx(12 / -2.5 / 0.8).epsilon(0.01));

	CHECK(mat.m[3][0] == doctest::Approx(13 / -2.5 / 0.8).epsilon(0.01));
	CHECK(mat.m[3][1] == doctest::Approx(14 / -2.5 / 0.8).epsilon(0.01));
	CHECK(mat.m[3][2] == doctest::Approx(0).epsilon(0.01));
	CHECK(mat.m[3][3] == doctest::Approx(-23.4 / -2.5 / 0.8).epsilon(0.01));
}