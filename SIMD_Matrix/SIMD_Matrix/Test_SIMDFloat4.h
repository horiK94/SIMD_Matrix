#pragma once
#include "SIMDFloat3.h"
#include "SIMDFloat4.h"
#include <xmmintrin.h>

#include "ThirdParty/doctest/doctest.h"

TEST_CASE("zero vector construct")
{
	SIMDFloat4 zeroVec = SIMDFloat4();
	CHECK(zeroVec.m.m128_f32[0] == 0);
	CHECK(zeroVec.m.m128_f32[1] == 0);
	CHECK(zeroVec.m.m128_f32[2] == 0);
	CHECK(zeroVec.m.m128_f32[3] == 0);
}

TEST_CASE("m.m128_f32[0] m.m128_f32[1] m.m128_f32[2] m.m128_f32[3] is inputed vector constructor")
{
	SIMDFloat4 v(-2, 0, 1.6, -76.5);
	CHECK(v.m.m128_f32[0] == doctest::Approx(-2).epsilon(0.01));
	CHECK(v.m.m128_f32[1] == doctest::Approx(0).epsilon(0.01));
	CHECK(v.m.m128_f32[2] == doctest::Approx(1.6).epsilon(0.01));
	CHECK(v.m.m128_f32[3] == doctest::Approx(-76.5).epsilon(0.01));
}

TEST_CASE("float[4] vector consturct")
{
	float e[4] = { -1, 0, 3.2, -0.9 };
	SIMDFloat4 v = SIMDFloat4(e);

	CHECK(v.m.m128_f32[0] == doctest::Approx(-1).epsilon(0.01));
	CHECK(v.m.m128_f32[1] == doctest::Approx(0).epsilon(0.01));
	CHECK(v.m.m128_f32[2] == doctest::Approx(3.2).epsilon(0.01));
	CHECK(v.m.m128_f32[3] == doctest::Approx(-0.9).epsilon(0.01));
}

TEST_CASE("SIMDFloat4 vector constuctor")
{
	SIMDFloat4 v(-3, 0.85, 0, 7.11);
	SIMDFloat4 w(v);

	CHECK(w.m.m128_f32[0] == doctest::Approx(-3).epsilon(0.01));
	CHECK(w.m.m128_f32[1] == doctest::Approx(0.85).epsilon(0.01));
	CHECK(w.m.m128_f32[2] == doctest::Approx(0).epsilon(0.01));
	CHECK(w.m.m128_f32[3] == doctest::Approx(7.11).epsilon(0.01));
}

TEST_CASE("(Float3, m.m128_f32[3]) is inputed vector constructor")
{
	SIMDFloat3 v(-2, 0, 1.6);
	double w = -9.33;
	SIMDFloat4 vec(v, w);

	CHECK(vec.m.m128_f32[0] == doctest::Approx(-2).epsilon(0.01));
	CHECK(vec.m.m128_f32[1] == doctest::Approx(0).epsilon(0.01));
	CHECK(vec.m.m128_f32[2] == doctest::Approx(1.6).epsilon(0.01));
	CHECK(vec.m.m128_f32[3] == doctest::Approx(-9.33).epsilon(0.01));
}

TEST_CASE("__m128 constructor")
{
	__m128 m = _mm_set_ps(-2, 0, 1.6, -76.5);
	SIMDFloat4 vec(m);

	CHECK(vec.m.m128_f32[0] == doctest::Approx(-76.5).epsilon(0.01));
	CHECK(vec.m.m128_f32[1] == doctest::Approx(1.6).epsilon(0.01));
	CHECK(vec.m.m128_f32[2] == doctest::Approx(0).epsilon(0.01));
	CHECK(vec.m.m128_f32[3] == doctest::Approx(-2).epsilon(0.01));
}

TEST_CASE("SIMDFloat4 + SIMDFloat4 calculation")
{
	SIMDFloat4 v(-2.6, 0.8, 0, 1.2);
	SIMDFloat4 w(2, 4, -1, -0.845);

	SIMDFloat4 plus = v + w;
	CHECK(plus.m.m128_f32[0] == doctest::Approx(-0.6).epsilon(0.01));
	CHECK(plus.m.m128_f32[1] == doctest::Approx(4.8).epsilon(0.01));
	CHECK(plus.m.m128_f32[2] == doctest::Approx(-1).epsilon(0.01));
	CHECK(plus.m.m128_f32[3] == doctest::Approx(0.355).epsilon(0.01));
}

TEST_CASE("SIMDFloat4 - SIMDFloat4 calculation")
{
	SIMDFloat4 v(2.6, 0, -.9, 6.11);
	SIMDFloat4 w(-3, 2, -1, 6.11);

	SIMDFloat4 minus = v - w;
	CHECK(minus.m.m128_f32[0] == doctest::Approx(5.6).epsilon(0.01));
	CHECK(minus.m.m128_f32[1] == doctest::Approx(-2).epsilon(0.01));
	CHECK(minus.m.m128_f32[2] == doctest::Approx(0.1).epsilon(0.01));
	CHECK(minus.m.m128_f32[3] == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("+SIMDFloat4 calculation")
{
	SIMDFloat4 v(-3, 1.6, 0, -.35);

	CHECK(+v.m.m128_f32[0] == doctest::Approx(-3).epsilon(0.01));
	CHECK(+v.m.m128_f32[1] == doctest::Approx(1.6).epsilon(0.01));
	CHECK(+v.m.m128_f32[2] == doctest::Approx(0).epsilon(0.01));
	CHECK(+v.m.m128_f32[3] == doctest::Approx(-0.35).epsilon(0.01));
}

TEST_CASE("+=SIMDFloat4 calculation")
{
	SIMDFloat4 a(1, 2, 3, -.5);
	SIMDFloat4 b(-0.5, 1.6, -3, 0.8);
	SIMDFloat4 c(0.2, -0.3, 0.4, -1.22);

	a += b += c;
	CHECK(a.m.m128_f32[0] == doctest::Approx(0.7).epsilon(0.01));
	CHECK(a.m.m128_f32[1] == doctest::Approx(3.3).epsilon(0.01));
	CHECK(a.m.m128_f32[2] == doctest::Approx(0.4).epsilon(0.01));
	CHECK(a.m.m128_f32[3] == doctest::Approx(-0.92).epsilon(0.01));

	CHECK(b.m.m128_f32[0] == doctest::Approx(-0.3).epsilon(0.01));
	CHECK(b.m.m128_f32[1] == doctest::Approx(1.3).epsilon(0.01));
	CHECK(b.m.m128_f32[2] == doctest::Approx(-2.6).epsilon(0.01));
	CHECK(b.m.m128_f32[3] == doctest::Approx(-0.42).epsilon(0.01));
}

TEST_CASE("-SIMDFloat4 calculation")
{
	SIMDFloat4 v(-3, 16.3, 0, 0.08);

	CHECK(-v.m.m128_f32[0] == doctest::Approx(3).epsilon(0.01));
	CHECK(-v.m.m128_f32[1] == doctest::Approx(-16.3).epsilon(0.01));
	CHECK(-v.m.m128_f32[2] == doctest::Approx(0).epsilon(0.01));
	CHECK(-v.m.m128_f32[3] == doctest::Approx(-0.08).epsilon(0.01));
}

TEST_CASE("-=SIMDFloat4 calculation")
{
	SIMDFloat4 a(1, 2, 3, -.5);
	SIMDFloat4 b(-0.5, 1.6, -3, 0.8);
	SIMDFloat4 c(0.2, -0.3, 0.4, -1.22);

	a -= b -= c;
	CHECK(a.m.m128_f32[0] == doctest::Approx(1.7).epsilon(0.01));
	CHECK(a.m.m128_f32[1] == doctest::Approx(0.1).epsilon(0.01));
	CHECK(a.m.m128_f32[2] == doctest::Approx(6.4).epsilon(0.01));
	CHECK(a.m.m128_f32[3] == doctest::Approx(-2.52).epsilon(0.01));

	CHECK(b.m.m128_f32[0] == doctest::Approx(-0.7).epsilon(0.01));
	CHECK(b.m.m128_f32[1] == doctest::Approx(1.9).epsilon(0.01));
	CHECK(b.m.m128_f32[2] == doctest::Approx(-3.4).epsilon(0.01));
	CHECK(b.m.m128_f32[3] == doctest::Approx(2.02).epsilon(0.01));
}

TEST_CASE("double * SIMDFloat4 calculation")
{
	double k = 9.3;
	SIMDFloat4 v(-3.3, 1, 0, 0.06);

	SIMDFloat4 val = k * v;
	CHECK(val.m.m128_f32[0] == doctest::Approx(-30.69).epsilon(0.01));
	CHECK(val.m.m128_f32[1] == doctest::Approx(9.3).epsilon(0.01));
	CHECK(val.m.m128_f32[2] == doctest::Approx(0).epsilon(0.01));
	CHECK(val.m.m128_f32[3] == doctest::Approx(0.558).epsilon(0.01));
}

TEST_CASE("SIMDFloat4 * double calculation")
{
	double k = 9.3;
	SIMDFloat4 v(-3.3, 1, 0, 0.06);

	SIMDFloat4 val = v * k;
	CHECK(val.m.m128_f32[0] == doctest::Approx(-30.69).epsilon(0.01));
	CHECK(val.m.m128_f32[1] == doctest::Approx(9.3).epsilon(0.01));
	CHECK(val.m.m128_f32[2] == doctest::Approx(0).epsilon(0.01));
	CHECK(val.m.m128_f32[3] == doctest::Approx(0.558).epsilon(0.01));
}

TEST_CASE("*= SIMDFloat4 constuctor")
{
	SIMDFloat4 v(-1, 2, 0.6, 0);
	double k1 = 2.5;
	double k2 = -1.72;

	(v *= k1) *= k2;
	CHECK(v.m.m128_f32[0] == doctest::Approx(4.3).epsilon(0.01));
	CHECK(v.m.m128_f32[1] == doctest::Approx(-8.6).epsilon(0.01));
	CHECK(v.m.m128_f32[2] == doctest::Approx(-2.58).epsilon(0.01));
	CHECK(v.m.m128_f32[3] == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("SIMDFloat4 / double calculation")
{
	SIMDFloat4 v(2.1, -6, 0, 0.68);
	double k = 7.7;

	SIMDFloat4 val = v / k;

	CHECK(val.m.m128_f32[0] == doctest::Approx(2.1 / 7.7).epsilon(0.01));
	CHECK(val.m.m128_f32[1] == doctest::Approx(-6.0 / 7.7).epsilon(0.01));
	CHECK(val.m.m128_f32[2] == doctest::Approx(0).epsilon(0.01));
	CHECK(val.m.m128_f32[3] == doctest::Approx(0.68 / 7.7).epsilon(0.01));
}

TEST_CASE("/= double calculation")
{
	SIMDFloat4 v(2.1, -6, 0, 0.64);
	double k1 = 7.7;
	double k2 = -1.2;

	(v /= k1) /= k2;
	CHECK(v.m.m128_f32[0] == doctest::Approx(2.1 / 7.7 / -1.2).epsilon(0.01));
	CHECK(v.m.m128_f32[1] == doctest::Approx(-6.0 / 7.7 / -1.2).epsilon(0.01));
	CHECK(v.m.m128_f32[2] == doctest::Approx(0).epsilon(0.01));
	CHECK(v.m.m128_f32[3] == doctest::Approx(0.64 / 7.7 / -1.2).epsilon(0.01));
}

TEST_CASE("Dot() calculation")
{
	SIMDFloat4 v(2.1, -6, 0, -1.234);
	SIMDFloat4 w(1, 2, 3, -0.6);

	double dot = SIMDFloat4::Dot(v, w);
	CHECK(dot == doctest::Approx(-9.1596).epsilon(0.01));
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
}

TEST_CASE("zero() calculation")
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
	CHECK(v.length() == doctest::Approx(6.47555063296).epsilon(0.01));
}

TEST_CASE("lengthSq() calculation")
{
	SIMDFloat4 v(2.1, -6, 0, -1.234);
	CHECK(v.squareLength() == doctest::Approx(41.932756).epsilon(0.01));
}

TEST_CASE("normalize() calculation")
{
	SIMDFloat4 v(2.1, -6, 0, -1.234);
	v.normalize();
	CHECK(v.m.m128_f32[0] == doctest::Approx(2.1 / 6.47555063296).epsilon(0.01));
	CHECK(v.m.m128_f32[1] == doctest::Approx(-6 / 6.47555063296).epsilon(0.01));
	CHECK(v.m.m128_f32[2] == doctest::Approx(0).epsilon(0.01));
	CHECK(v.m.m128_f32[3] == doctest::Approx(-1.234 / 6.47555063296).epsilon(0.01));
}

TEST_CASE("Normalize() calculation")
{
	SIMDFloat4 v = SIMDFloat4::Normalize(SIMDFloat4(2.1, -6, 0, -1.234));
	CHECK(v.m.m128_f32[0] == doctest::Approx(2.1 / 6.47555063296).epsilon(0.01));
	CHECK(v.m.m128_f32[1] == doctest::Approx(-6 / 6.47555063296).epsilon(0.01));
	CHECK(v.m.m128_f32[2] == doctest::Approx(0).epsilon(0.01));
	CHECK(v.m.m128_f32[3] == doctest::Approx(-1.234 / 6.47555063296).epsilon(0.01));

}