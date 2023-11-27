#pragma once
#include "SIMDFloat3.h"
#include "ThirdParty/doctest/doctest.h"

TEST_CASE("zero vector construct")
{
	SIMDFloat3 zeroVec = SIMDFloat3();
	CHECK(zeroVec.getX() == 0);
	CHECK(zeroVec.getY() == 0);
	CHECK(zeroVec.getZ() == 0);
}

TEST_CASE("SIMDFloat3 vector constuctor")
{
	SIMDFloat3 v(-3, 0.85, 0);
	SIMDFloat3 w(v);

	CHECK(w.getX() == doctest::Approx(-3).epsilon(0.01));
	CHECK(w.getY() == doctest::Approx(0.85).epsilon(0.01));
	CHECK(w.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("x y z is inputed vector constructor")
{
	SIMDFloat3 v(-2, 0, 1.6);
	CHECK(v.getX() == doctest::Approx(-2).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(0).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(1.6).epsilon(0.01));
}

TEST_CASE("float[3] vector consturct")
{
	float e[3] = { -1, 0, 3.2 };
	SIMDFloat3 v = SIMDFloat3(e);

	CHECK(v.getX() == doctest::Approx(-1).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(0).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(3.2).epsilon(0.01));
}

TEST_CASE("__m128 constructor")
{
	__m128 m = _mm_set_ps(0, 0, 1.6, -76.5);
	SIMDFloat3 vec(m);

	CHECK(vec.getX() == doctest::Approx(-76.5).epsilon(0.01));
	CHECK(vec.getY() == doctest::Approx(1.6).epsilon(0.01));
	CHECK(vec.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("__m128 constructor use _mm_set_ps()")
{
	__m128 m = _mm_set_ps(-2, 2, 1.6, -76.5);
	SIMDFloat3 vec(m);

	CHECK(vec.getX() == doctest::Approx(-76.5).epsilon(0.01));
	CHECK(vec.getY() == doctest::Approx(1.6).epsilon(0.01));
	CHECK(vec.getZ() == doctest::Approx(2).epsilon(0.01));
}

TEST_CASE("SIMDFloat3 = SIMDFloat3 calculation")
{
	SIMDFloat3 v(-2.6, 0.8, 0);
	SIMDFloat3 w(2, 4, -1);

	v = w;
	CHECK(v.getX() == doctest::Approx(2).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(4).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(-1).epsilon(0.01));
}

TEST_CASE("SIMDFloat3 = SIMDFloat3 calculation use _mm_set_ps()")
{
	SIMDFloat3 v(-2.6, 0.8, 0);
	SIMDFloat3 w(_mm_set_ps(1, 2, 3, 4));

	v = w;
	CHECK(v.getX() == doctest::Approx(4).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(3).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(2).epsilon(0.01));
}

TEST_CASE("SIMDFloat3 = SIMDFloat3 calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(1, 2, 3, 4));
	SIMDFloat3 w(-2.6, 0.8, 0);

	v = w;
	CHECK(v.getX() == doctest::Approx(-2.6).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(0.8).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("SIMDFloat3 + SIMDFloat3 calculation")
{
	SIMDFloat3 v(-2.6, 0.8, 0);
	SIMDFloat3 w(2, 4, -1);

	SIMDFloat3 plus = v + w;
	CHECK(plus.getX() == doctest::Approx(-0.6).epsilon(0.01));
	CHECK(plus.getY() == doctest::Approx(4.8).epsilon(0.01));
	CHECK(plus.getZ() == doctest::Approx(-1).epsilon(0.01));
}

TEST_CASE("SIMDFloat3 + SIMDFloat3 calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(1, 2, 3, 4));
	SIMDFloat3 w(_mm_set_ps(5, 6, 7, 8));

	SIMDFloat3 plus = v + w;
	CHECK(plus.getX() == doctest::Approx(12).epsilon(0.01));
	CHECK(plus.getY() == doctest::Approx(10).epsilon(0.01));
	CHECK(plus.getZ() == doctest::Approx(8).epsilon(0.01));
}

TEST_CASE("SIMDFloat3 - SIMDFloat3 calculation")
{
	SIMDFloat3 v(2.6, 0, -.9);
	SIMDFloat3 w(-3, 2, -1);

	SIMDFloat3 minus = v - w;
	CHECK(minus.getX() == doctest::Approx(5.6).epsilon(0.01));
	CHECK(minus.getY() == doctest::Approx(-2).epsilon(0.01));
	CHECK(minus.getZ() == doctest::Approx(0.1).epsilon(0.01));
}

TEST_CASE("SIMDFloat3 - SIMDFloat3 calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(1, 2, 3, 4));
	SIMDFloat3 w(_mm_set_ps(2, 4, 6, 8));

	SIMDFloat3 minus = v - w;
	CHECK(minus.getX() == doctest::Approx(-4).epsilon(0.01));
	CHECK(minus.getY() == doctest::Approx(-3).epsilon(0.01));
	CHECK(minus.getZ() == doctest::Approx(-2).epsilon(0.01));
}

TEST_CASE("+SIMDFloat3 calculation")
{
	SIMDFloat3 v(-3, 1.6, 0);

	CHECK(+v.getX() == doctest::Approx(-3).epsilon(0.01));
	CHECK(+v.getY() == doctest::Approx(1.6).epsilon(0.01));
	CHECK(+v.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("+SIMDFloat3 calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(1, 2, 3, 4));

	CHECK(+v.getX() == doctest::Approx(4).epsilon(0.01));
	CHECK(+v.getY() == doctest::Approx(3).epsilon(0.01));
	CHECK(+v.getZ() == doctest::Approx(2).epsilon(0.01));
}

TEST_CASE("+=SIMDFloat3 calculation")
{
	SIMDFloat3 a(1, 2, 3);
	SIMDFloat3 b(-0.5, 1.6, -3);
	SIMDFloat3 c(0.2, -0.3, 0.4);

	a += b += c;
	CHECK(a.getX() == doctest::Approx(0.7).epsilon(0.01));
	CHECK(a.getY() == doctest::Approx(3.3).epsilon(0.01));
	CHECK(a.getZ() == doctest::Approx(0.4).epsilon(0.01));

	CHECK(b.getX() == doctest::Approx(-0.3).epsilon(0.01));
	CHECK(b.getY() == doctest::Approx(1.3).epsilon(0.01));
	CHECK(b.getZ() == doctest::Approx(-2.6).epsilon(0.01));
}

TEST_CASE("+=SIMDFloat3 calculation use _mm_set_ps()")
{
	SIMDFloat3 a(_mm_set_ps(1, 2, 3, 4));
	SIMDFloat3 b(_mm_set_ps(-2, 4, -6, 8));

	a += b;
	CHECK(a.getX() == doctest::Approx(12).epsilon(0.01));
	CHECK(a.getY() == doctest::Approx(-3).epsilon(0.01));
	CHECK(a.getZ() == doctest::Approx(6).epsilon(0.01));
}

TEST_CASE("-SIMDFloat3 calculation")
{
	SIMDFloat3 v(-3, 16.3, 0);

	CHECK(-v.getX() == doctest::Approx(3).epsilon(0.01));
	CHECK(-v.getY() == doctest::Approx(-16.3).epsilon(0.01));
	CHECK(-v.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("-SIMDFloat3 calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(1, 2, 3, 4));

	CHECK(-v.getX() == doctest::Approx(-4).epsilon(0.01));
	CHECK(-v.getY() == doctest::Approx(-3).epsilon(0.01));
	CHECK(-v.getZ() == doctest::Approx(-2).epsilon(0.01));
}

TEST_CASE("-=SIMDFloat3 calculation")
{
	SIMDFloat3 a(1, 2, 3);
	SIMDFloat3 b(-0.5, 1.6, -3);
	SIMDFloat3 c(0.2, -0.3, 0.4);

	a -= b -= c;
	CHECK(a.getX() == doctest::Approx(1.7).epsilon(0.01));
	CHECK(a.getY() == doctest::Approx(0.1).epsilon(0.01));
	CHECK(a.getZ() == doctest::Approx(6.4).epsilon(0.01));

	CHECK(b.getX() == doctest::Approx(-0.7).epsilon(0.01));
	CHECK(b.getY() == doctest::Approx(1.9).epsilon(0.01));
	CHECK(b.getZ() == doctest::Approx(-3.4).epsilon(0.01));
}

TEST_CASE("-=SIMDFloat3 calculation use _mm_set_ps()")
{
	SIMDFloat3 a(_mm_set_ps(1, 2, 3, 4));
	SIMDFloat3 b(_mm_set_ps(-2, 4, -6, 8));

	a -= b;
	CHECK(a.getX() == doctest::Approx(-4).epsilon(0.01));
	CHECK(a.getY() == doctest::Approx(9).epsilon(0.01));
	CHECK(a.getZ() == doctest::Approx(-2).epsilon(0.01));
}


TEST_CASE("double * SIMDFloat3 calculation")
{
	double k = 9.3;
	SIMDFloat3 v(-3.3, 1, 0);

	SIMDFloat3 val = k * v;
	CHECK(val.getX() == doctest::Approx(-30.69).epsilon(0.01));
	CHECK(val.getY() == doctest::Approx(9.3).epsilon(0.01));
	CHECK(val.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("double * SIMDFloat3 calculation use _mm_set_ps()")
{
	double k = -1;
	SIMDFloat3 v(_mm_set_ps(1, 2, 3, 4));

	SIMDFloat3 val = k * v;
	CHECK(val.getX() == doctest::Approx(-4).epsilon(0.01));
	CHECK(val.getY() == doctest::Approx(-3).epsilon(0.01));
	CHECK(val.getZ() == doctest::Approx(-2).epsilon(0.01));
}

TEST_CASE("SIMDFloat3 * double calculation")
{
	double k = 9.3;
	SIMDFloat3 v(-3.3, 1, 0);

	SIMDFloat3 val = v * k;
	CHECK(val.getX() == doctest::Approx(-30.69).epsilon(0.01));
	CHECK(val.getY() == doctest::Approx(9.3).epsilon(0.01));
	CHECK(val.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("SIMDFloat3 * double calculation use _mm_set_ps()")
{
	double k = -1;
	SIMDFloat3 v(_mm_set_ps(1, 2, 3, 4));

	SIMDFloat3 val = v * k;
	CHECK(val.getX() == doctest::Approx(-4).epsilon(0.01));
	CHECK(val.getY() == doctest::Approx(-3).epsilon(0.01));
	CHECK(val.getZ() == doctest::Approx(-2).epsilon(0.01));
}

TEST_CASE("*= SIMDFloat3 constuctor")
{
	SIMDFloat3 v(-1, 2, 0.6);
	double k1 = 2.5;
	double k2 = -1.72;

	(v *= k1) *= k2;
	CHECK(v.getX() == doctest::Approx(4.3).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-8.6).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(-2.58).epsilon(0.01));
}

TEST_CASE("*= SIMDFloat3 constuctor use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(1, 2, 3, 4));
	double k1 = 2.5;

	v *= k1;
	CHECK(v.getX() == doctest::Approx(10).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(7.5).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(5).epsilon(0.01));
}

TEST_CASE("SIMDFloat3 / double calculation")
{
	SIMDFloat3 v(2.1, -6, 0);
	double k = 7.7;

	SIMDFloat3 val = v / k;

	CHECK(val.getX() == doctest::Approx(2.1 / 7.7).epsilon(0.01));
	CHECK(val.getY() == doctest::Approx(-6.0 / 7.7).epsilon(0.01));
	CHECK(val.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("SIMDFloat3 / double calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(1, 2, 3, 4));
	double k = 2;

	SIMDFloat3 val = v / k;

	CHECK(val.getX() == doctest::Approx(2).epsilon(0.01));
	CHECK(val.getY() == doctest::Approx(1.5).epsilon(0.01));
	CHECK(val.getZ() == doctest::Approx(1).epsilon(0.01));
}

TEST_CASE("/= double calculation")
{
	SIMDFloat3 v(2.1, -6, 0);
	double k1 = 7.7;
	double k2 = -1.2;

	(v /= k1) /= k2;
	CHECK(v.getX() == doctest::Approx(2.1 / 7.7 / -1.2).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-6.0 / 7.7 / -1.2).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("/= double calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(1, 2, 3, 4));
	double k = 2;

	v /= k;
	CHECK(v.getX() == doctest::Approx(2).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(1.5).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(1).epsilon(0.01));
}

TEST_CASE("Cross() calculation")
{
	SIMDFloat3 v(2.1, -6, 0);
	SIMDFloat3 w(1, 2, 3);

	SIMDFloat3 cross = SIMDFloat3::Cross(v, w);
	CHECK(cross.getX() == doctest::Approx(-18).epsilon(0.01));
	CHECK(cross.getY() == doctest::Approx(-6.3).epsilon(0.01));
	CHECK(cross.getZ() == doctest::Approx(10.2).epsilon(0.01));
}

TEST_CASE("Cross() calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(3, 0, -6, 2.1));
	SIMDFloat3 w(_mm_set_ps(4, 3, 2, 1));

	SIMDFloat3 cross = SIMDFloat3::Cross(v, w);
	CHECK(cross.getX() == doctest::Approx(-18).epsilon(0.01));
	CHECK(cross.getY() == doctest::Approx(-6.3).epsilon(0.01));
	CHECK(cross.getZ() == doctest::Approx(10.2).epsilon(0.01));
}

TEST_CASE("equal() calculation")
{
	SIMDFloat3 v(2.1, -6, 0);
	SIMDFloat3 w1(2.1, -6.0, 0);
	float epsilon = 0.01;

	CHECK(v.equal(w1, epsilon));

	SIMDFloat3 w2(2.08, -6, 0);
	CHECK_FALSE(v.equal(w2, epsilon));

	SIMDFloat3 w3(2.1, -6.02, 0);
	CHECK_FALSE(v.equal(w3, epsilon));

	SIMDFloat3 w4(2.1, -6, 0.02);
	CHECK_FALSE(v.equal(w4, epsilon));
}

TEST_CASE("equal() calculation  use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(2.1, -6, 0, 1));
	SIMDFloat3 w1(_mm_set_ps(-7, -6, 0, 1));
	float epsilon = 0.01;

	CHECK(v.equal(w1, epsilon));

	SIMDFloat3 w2(_mm_set_ps(2.1, -5, 0, 1));
	CHECK_FALSE(v.equal(w2, epsilon));

	SIMDFloat3 w3(_mm_set_ps(2.1, -6, 1, 1));
	CHECK_FALSE(v.equal(w3, epsilon));

	SIMDFloat3 w4(_mm_set_ps(2.1, -6, 0, 2));
	CHECK_FALSE(v.equal(w4, epsilon));
}

TEST_CASE("isZero() calculation")
{
	SIMDFloat3 z1 = SIMDFloat3();
	SIMDFloat3 z2 = SIMDFloat3(0.01, 0, 0);
	SIMDFloat3 z3 = SIMDFloat3(0, 0.01, 0);
	SIMDFloat3 z4 = SIMDFloat3(0, 0, 0.01);

	CHECK(z1.isZero());
	CHECK_FALSE(z2.isZero());
	CHECK_FALSE(z3.isZero());
	CHECK_FALSE(z4.isZero());
}

TEST_CASE("isZero() calculation use _mm_set_ps()")
{
	SIMDFloat3 z1 = SIMDFloat3(_mm_set_ps(1, 0, 0, 0));
	SIMDFloat3 z2 = SIMDFloat3(_mm_set_ps(0, 0.01, 0, 0));
	SIMDFloat3 z3 = SIMDFloat3(_mm_set_ps(0, 0, 0.01, 0));
	SIMDFloat3 z4 = SIMDFloat3(_mm_set_ps(0, 0, 0, 0.01));

	CHECK(z1.isZero());
	CHECK_FALSE(z2.isZero());
	CHECK_FALSE(z3.isZero());
	CHECK_FALSE(z4.isZero());
}

TEST_CASE("length() calculation")
{
	SIMDFloat3 v(2.1, -6, 0);

	SIMDFloat3 length = v.length();
	CHECK(length.getX() == doctest::Approx(6.35688603013).epsilon(0.01));
	CHECK(length.getY() == doctest::Approx(6.35688603013).epsilon(0.01));
	CHECK(length.getZ() == doctest::Approx(6.35688603013).epsilon(0.01));
}

TEST_CASE("length() calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(5, 0, -6, 2.1));

	SIMDFloat3 length = v.length();
	CHECK(length.getX() == doctest::Approx(6.35688603013).epsilon(0.01));
	CHECK(length.getY() == doctest::Approx(6.35688603013).epsilon(0.01));
	CHECK(length.getZ() == doctest::Approx(6.35688603013).epsilon(0.01));
}

TEST_CASE("squareLength() calculation")
{
	SIMDFloat3 v(2.1, -6, 0);

	SIMDFloat3 sqrLength = v.squareLength();
	CHECK(sqrLength.getX() == doctest::Approx(40.41).epsilon(0.01));
	CHECK(sqrLength.getY() == doctest::Approx(40.41).epsilon(0.01));
	CHECK(sqrLength.getZ() == doctest::Approx(40.41).epsilon(0.01));
}

TEST_CASE("squareLength() calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(5, 0, -6, 2.1));

	SIMDFloat3 sqrLength = v.squareLength();
	CHECK(sqrLength.getX() == doctest::Approx(40.41).epsilon(0.01));
	CHECK(sqrLength.getY() == doctest::Approx(40.41).epsilon(0.01));
	CHECK(sqrLength.getZ() == doctest::Approx(40.41).epsilon(0.01));
}

TEST_CASE("normalize() calculation")
{
	SIMDFloat3 v(2.1, -6, 0);
	v.normalize();
	CHECK(v.getX() == doctest::Approx(2.1 / 6.35688603013).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-6 / 6.35688603013).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("normalize() calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(5, 0, -6, 2.1));
	v.normalize();
	CHECK(v.getX() == doctest::Approx(2.1 / 6.35688603013).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-6 / 6.35688603013).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("normalized() calculation")
{
	SIMDFloat3 v(2.1, -6, 0);
	SIMDFloat3 w = v.normalized();

	CHECK(v.getX() == doctest::Approx(2.1).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-6).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(0).epsilon(0.01));

	CHECK(w.getX() == doctest::Approx(2.1 / 6.35688603013).epsilon(0.01));
	CHECK(w.getY() == doctest::Approx(-6 / 6.35688603013).epsilon(0.01));
	CHECK(w.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("getX() checked")
{
	SIMDFloat3 v{};
	v.m = _mm_set_ps(1.5, -2, 0, 4);

	CHECK(v.getX() == doctest::Approx(4).epsilon(0.01));
}

TEST_CASE("getY() checked")
{
	SIMDFloat3 v{};
	v.m = _mm_set_ps(1.5, -2, 0, 4);

	CHECK(v.getY() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("getZ() checked")
{
	SIMDFloat3 v{};
	v.m = _mm_set_ps(1.5, -2, 0, 4);

	CHECK(v.getZ() == doctest::Approx(-2).epsilon(0.01));
}

TEST_CASE("normalized() calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(5, 0, -6, 2.1));
	SIMDFloat3 w = v.normalized();

	CHECK(w.getX() == doctest::Approx(2.1 / 6.35688603013).epsilon(0.01));
	CHECK(w.getY() == doctest::Approx(-6 / 6.35688603013).epsilon(0.01));
	CHECK(w.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("storeValue() checked")
{
	SIMDFloat3 v{};
	v.m = _mm_set_ps(0, -2, 0, 4);

	CHECK(v.getX() == doctest::Approx(4).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(0).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(-2).epsilon(0.01));
}

TEST_CASE("Dot() calculation")
{
	SIMDFloat3 v(2.1, -6, 0);
	SIMDFloat3 w(1, 2, 3);

	SIMDFloat3 dot = SIMDFloat3::Dot(v, w);
	CHECK(dot.getX() == doctest::Approx(-9.9).epsilon(0.01));
	CHECK(dot.getY() == doctest::Approx(-9.9).epsilon(0.01));
	CHECK(dot.getZ() == doctest::Approx(-9.9).epsilon(0.01));
}

TEST_CASE("Dot() calculation use _mm_set_ps()")
{
	SIMDFloat3 v(_mm_set_ps(5, 0, -6, 2.1));
	SIMDFloat3 w(_mm_set_ps(4, 3, 2, 1));

	SIMDFloat3 dot = SIMDFloat3::Dot(v, w);
	CHECK(dot.getX() == doctest::Approx(-9.9).epsilon(0.01));
	CHECK(dot.getY() == doctest::Approx(-9.9).epsilon(0.01));
	CHECK(dot.getZ() == doctest::Approx(-9.9).epsilon(0.01));
}


TEST_CASE("Normalize() calculation")
{
	SIMDFloat3 v = SIMDFloat3::Normalize(SIMDFloat3(2.1, -6, 0));
	CHECK(v.getX() == doctest::Approx(2.1 / 6.35688603013).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-6 / 6.35688603013).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("Normalize() calculation use _mm_set_ps()")
{
	SIMDFloat3 v = SIMDFloat3::Normalize(SIMDFloat3(_mm_set_ps(5, 0, -6, 2.1)));
	CHECK(v.getX() == doctest::Approx(2.1 / 6.35688603013).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-6 / 6.35688603013).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(0).epsilon(0.01));
}