#pragma once
#include "SIMDFloat3.h"
#include "SIMDFloat4.h"
#include <xmmintrin.h>

#include "ThirdParty/doctest/doctest.h"

TEST_CASE("zero vector construct")
{
	SIMDFloat4 zeroVec = SIMDFloat4();
	CHECK(zeroVec.getX() == 0);
	CHECK(zeroVec.getY() == 0);
	CHECK(zeroVec.getZ() == 0);
	CHECK(zeroVec.getW() == 0);
}

TEST_CASE("SIMDFloat4 vector constuctor")
{
	SIMDFloat4 v(-3, 0.85, 0, 7.11);
	SIMDFloat4 w(v);

	CHECK(w.getX() == doctest::Approx(-3).epsilon(0.01));
	CHECK(w.getY() == doctest::Approx(0.85).epsilon(0.01));
	CHECK(w.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(w.getW() == doctest::Approx(7.11).epsilon(0.01));
}

TEST_CASE("x y z w is inputed vector constructor")
{
	SIMDFloat4 v(-2, 0, 1.6, -76.5);
	CHECK(v.getX() == doctest::Approx(-2).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(0).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(1.6).epsilon(0.01));
	CHECK(v.getW() == doctest::Approx(-76.5).epsilon(0.01));
}


TEST_CASE("(SIMDFloat3, getW()) is inputed vector constructor")
{
	SIMDFloat3 v(-2, 0, 1.6);
	double w = -9.33;
	SIMDFloat4 vec(v, w);

	CHECK(vec.getX() == doctest::Approx(-2).epsilon(0.01));
	CHECK(vec.getY() == doctest::Approx(0).epsilon(0.01));
	CHECK(vec.getZ() == doctest::Approx(1.6).epsilon(0.01));
	CHECK(vec.getW() == doctest::Approx(-9.33).epsilon(0.01));
}

TEST_CASE("float[4] vector consturct")
{
	float e[4] = { -1, 0, 3.2, -0.9 };
	SIMDFloat4 v = SIMDFloat4(e);

	CHECK(v.getX() == doctest::Approx(-1).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(0).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(3.2).epsilon(0.01));
	CHECK(v.getW() == doctest::Approx(-0.9).epsilon(0.01));
}

TEST_CASE("__m128 constructor")
{
	__m128 m = _mm_set_ps(-2, 0, 1.6, -76.5);
	SIMDFloat4 vec(m);

	CHECK(vec.getX() == doctest::Approx(-76.5).epsilon(0.01));
	CHECK(vec.getY() == doctest::Approx(1.6).epsilon(0.01));
	CHECK(vec.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(vec.getW() == doctest::Approx(-2).epsilon(0.01));
}

TEST_CASE("SIMDFloat4 + SIMDFloat4 calculation")
{
	SIMDFloat4 v(-2.6, 0.8, 0, 1.2);
	SIMDFloat4 w(2, 4, -1, -0.845);

	SIMDFloat4 plus = v + w;
	CHECK(plus.getX() == doctest::Approx(-0.6).epsilon(0.01));
	CHECK(plus.getY() == doctest::Approx(4.8).epsilon(0.01));
	CHECK(plus.getZ() == doctest::Approx(-1).epsilon(0.01));
	CHECK(plus.getW() == doctest::Approx(0.355).epsilon(0.01));
}

TEST_CASE("+=SIMDFloat4 calculation")
{
	SIMDFloat4 a(1, 2, 3, -.5);
	SIMDFloat4 b(-0.5, 1.6, -3, 0.8);
	SIMDFloat4 c(0.2, -0.3, 0.4, -1.22);

	a += b += c;
	CHECK(a.getX() == doctest::Approx(0.7).epsilon(0.01));
	CHECK(a.getY() == doctest::Approx(3.3).epsilon(0.01));
	CHECK(a.getZ() == doctest::Approx(0.4).epsilon(0.01));
	CHECK(a.getW() == doctest::Approx(-0.92).epsilon(0.01));

	CHECK(b.getX() == doctest::Approx(-0.3).epsilon(0.01));
	CHECK(b.getY() == doctest::Approx(1.3).epsilon(0.01));
	CHECK(b.getZ() == doctest::Approx(-2.6).epsilon(0.01));
	CHECK(b.getW() == doctest::Approx(-0.42).epsilon(0.01));
}

TEST_CASE("+SIMDFloat4 calculation")
{
	SIMDFloat4 v(-3, 1.6, 0, -.35);

	CHECK(+v.getX() == doctest::Approx(-3).epsilon(0.01));
	CHECK(+v.getY() == doctest::Approx(1.6).epsilon(0.01));
	CHECK(+v.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(+v.getW() == doctest::Approx(-0.35).epsilon(0.01));
}

TEST_CASE("SIMDFloat4 - SIMDFloat4 calculation")
{
	SIMDFloat4 v(2.6, 0, -.9, 6.11);
	SIMDFloat4 w(-3, 2, -1, 6.11);

	SIMDFloat4 minus = v - w;
	CHECK(minus.getX() == doctest::Approx(5.6).epsilon(0.01));
	CHECK(minus.getY() == doctest::Approx(-2).epsilon(0.01));
	CHECK(minus.getZ() == doctest::Approx(0.1).epsilon(0.01));
	CHECK(minus.getW() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("-=SIMDFloat4 calculation")
{
	SIMDFloat4 a(1, 2, 3, -.5);
	SIMDFloat4 b(-0.5, 1.6, -3, 0.8);
	SIMDFloat4 c(0.2, -0.3, 0.4, -1.22);

	a -= b -= c;
	CHECK(a.getX() == doctest::Approx(1.7).epsilon(0.01));
	CHECK(a.getY() == doctest::Approx(0.1).epsilon(0.01));
	CHECK(a.getZ() == doctest::Approx(6.4).epsilon(0.01));
	CHECK(a.getW() == doctest::Approx(-2.52).epsilon(0.01));

	CHECK(b.getX() == doctest::Approx(-0.7).epsilon(0.01));
	CHECK(b.getY() == doctest::Approx(1.9).epsilon(0.01));
	CHECK(b.getZ() == doctest::Approx(-3.4).epsilon(0.01));
	CHECK(b.getW() == doctest::Approx(2.02).epsilon(0.01));
}

TEST_CASE("-SIMDFloat4 calculation")
{
	SIMDFloat4 v(-3, 16.3, 0, 0.08);

	CHECK(-v.getX() == doctest::Approx(3).epsilon(0.01));
	CHECK(-v.getY() == doctest::Approx(-16.3).epsilon(0.01));
	CHECK(-v.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(-v.getW() == doctest::Approx(-0.08).epsilon(0.01));
}

TEST_CASE("double * SIMDFloat4 calculation")
{
	double k = 9.3;
	SIMDFloat4 v(-3.3, 1, 0, 0.06);

	SIMDFloat4 val = k * v;
	CHECK(val.getX() == doctest::Approx(-30.69).epsilon(0.01));
	CHECK(val.getY() == doctest::Approx(9.3).epsilon(0.01));
	CHECK(val.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(val.getW() == doctest::Approx(0.558).epsilon(0.01));
}

TEST_CASE("SIMDFloat4 * double calculation")
{
	double k = 9.3;
	SIMDFloat4 v(-3.3, 1, 0, 0.06);

	SIMDFloat4 val = v * k;
	CHECK(val.getX() == doctest::Approx(-30.69).epsilon(0.01));
	CHECK(val.getY() == doctest::Approx(9.3).epsilon(0.01));
	CHECK(val.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(val.getW() == doctest::Approx(0.558).epsilon(0.01));
}

TEST_CASE("*= SIMDFloat4 constuctor")
{
	SIMDFloat4 v(-1, 2, 0.6, 0);
	double k1 = 2.5;
	double k2 = -1.72;

	(v *= k1) *= k2;
	CHECK(v.getX() == doctest::Approx(4.3).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-8.6).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(-2.58).epsilon(0.01));
	CHECK(v.getW() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("SIMDFloat4 / double calculation")
{
	SIMDFloat4 v(2.1, -6, 0, 0.68);
	double k = 7.7;

	SIMDFloat4 val = v / k;

	CHECK(val.getX() == doctest::Approx(2.1 / 7.7).epsilon(0.01));
	CHECK(val.getY() == doctest::Approx(-6.0 / 7.7).epsilon(0.01));
	CHECK(val.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(val.getW() == doctest::Approx(0.68 / 7.7).epsilon(0.01));
}

TEST_CASE("/= double calculation")
{
	SIMDFloat4 v(2.1, -6, 0, 0.64);
	double k1 = 7.7;
	double k2 = -1.2;

	(v /= k1) /= k2;
	CHECK(v.getX() == doctest::Approx(2.1 / 7.7 / -1.2).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-6.0 / 7.7 / -1.2).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(v.getW() == doctest::Approx(0.64 / 7.7 / -1.2).epsilon(0.01));
}

TEST_CASE("equal() calculation")
{
	SIMDFloat4 v(2.1, -6, 0, -1.234);
	SIMDFloat4 w1(2.1, -6, 0, -1.234);
	float epsilon = 0.01;

	CHECK(v.equal(w1, epsilon));

	SIMDFloat4 w2(2.08, -6, 0, -1.234);
	CHECK_FALSE(v.equal(w2, epsilon));

	SIMDFloat4 w3(2.1, -6.02, 0, -1.234);
	CHECK_FALSE(v.equal(w3, epsilon));

	SIMDFloat4 w4(2.1, -6, 0.02, -1.234);
	CHECK_FALSE(v.equal(w4, epsilon));

	SIMDFloat4 w5(2.1, -6, 0, -1.2);
	CHECK_FALSE(v.equal(w5, epsilon));
}

TEST_CASE("isZero() calculation")
{
	SIMDFloat4 z1 = SIMDFloat4();
	SIMDFloat4 z2 = SIMDFloat4(0.01, 0, 0, 0);
	SIMDFloat4 z3 = SIMDFloat4(0, 0.01, 0, 0);
	SIMDFloat4 z4 = SIMDFloat4(0, 0, 0.01, 0);
	SIMDFloat4 z5 = SIMDFloat4(0, 0, 0, -0.01);

	CHECK(z1.isZero());
	CHECK_FALSE(z2.isZero());
	CHECK_FALSE(z3.isZero());
	CHECK_FALSE(z4.isZero());
	CHECK_FALSE(z5.isZero());
}

TEST_CASE("length() calculation")
{
	SIMDFloat4 v(2.1, -6, 0, -1.234);
	SIMDFloat4 length = v.length();
	CHECK(length.getX() == doctest::Approx(6.47555063296).epsilon(0.01));
	CHECK(length.getY() == doctest::Approx(6.47555063296).epsilon(0.01));
	CHECK(length.getZ() == doctest::Approx(6.47555063296).epsilon(0.01));
	CHECK(length.getW() == doctest::Approx(6.47555063296).epsilon(0.01));
}

TEST_CASE("squareLength() calculation")
{
	SIMDFloat4 v(2.1, -6, 0, -1.234);
	SIMDFloat4 lengthSq = v.squareLength();

	CHECK(lengthSq.getX() == doctest::Approx(41.932756).epsilon(0.01));
	CHECK(lengthSq.getY() == doctest::Approx(41.932756).epsilon(0.01));
	CHECK(lengthSq.getZ() == doctest::Approx(41.932756).epsilon(0.01));
	CHECK(lengthSq.getW() == doctest::Approx(41.932756).epsilon(0.01));
}

TEST_CASE("normalize() calculation")
{
	SIMDFloat4 v(2.1, -6, 0, -1.234);
	v.normalize();
	CHECK(v.getX() == doctest::Approx(2.1 / 6.47555063296).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-6 / 6.47555063296).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(v.getW() == doctest::Approx(-1.234 / 6.47555063296).epsilon(0.01));
}

TEST_CASE("normalized() calculation")
{
	SIMDFloat4 v(2.1, -6, 0, -1.234);
	SIMDFloat4 w = v.normalized();

	CHECK(v.getX() == doctest::Approx(2.1).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-6).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(v.getW() == doctest::Approx(-1.234).epsilon(0.01));

	CHECK(w.getX() == doctest::Approx(2.1 / 6.47555063296).epsilon(0.01));
	CHECK(w.getY() == doctest::Approx(-6 / 6.47555063296).epsilon(0.01));
	CHECK(w.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(w.getW() == doctest::Approx(-1.234 / 6.47555063296).epsilon(0.01));
}

TEST_CASE("getX() checked")
{
	SIMDFloat4 v{};
	v.m = _mm_set_ps(1.5, -2, 0, 4);

	CHECK(v.getX() == doctest::Approx(4).epsilon(0.01));
}

TEST_CASE("getY() checked")
{
	SIMDFloat4 v{};
	v.m = _mm_set_ps(1.5, -2, 0, 4);

	CHECK(v.getY() == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("getZ() checked")
{
	SIMDFloat4 v{};
	v.m = _mm_set_ps(1.5, -2, 0, 4);

	CHECK(v.getZ() == doctest::Approx(-2).epsilon(0.01));
}

TEST_CASE("getW() checked")
{
	SIMDFloat4 v{};
	v.m = _mm_set_ps(1.5, -2, 0, 4);

	CHECK(v.getW() == doctest::Approx(1.5).epsilon(0.01));
}


TEST_CASE("Dot() calculation")
{
	SIMDFloat4 v(2.1, -6, 0, -1.234);
	SIMDFloat4 w(1, 2, 3, -0.6);

	SIMDFloat4 dot = SIMDFloat4::Dot(v, w);
	CHECK(dot.getX() == doctest::Approx(-9.1596).epsilon(0.01));
	CHECK(dot.getY() == doctest::Approx(-9.1596).epsilon(0.01));
	CHECK(dot.getZ() == doctest::Approx(-9.1596).epsilon(0.01));
	CHECK(dot.getW() == doctest::Approx(-9.1596).epsilon(0.01));
}

TEST_CASE("Normalize() calculation")
{
	SIMDFloat4 v = SIMDFloat4::Normalize(SIMDFloat4(2.1, -6, 0, -1.234));
	CHECK(v.getX() == doctest::Approx(2.1 / 6.47555063296).epsilon(0.01));
	CHECK(v.getY() == doctest::Approx(-6 / 6.47555063296).epsilon(0.01));
	CHECK(v.getZ() == doctest::Approx(0).epsilon(0.01));
	CHECK(v.getW() == doctest::Approx(-1.234 / 6.47555063296).epsilon(0.01));
}