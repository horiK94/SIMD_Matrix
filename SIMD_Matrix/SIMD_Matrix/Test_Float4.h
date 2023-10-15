#pragma once
#include "Float3.h"
#include "Float4.h"

#include "ThirdParty/doctest/doctest.h"

TEST_CASE("zero vector construct")
{
	Float4 zeroVec = Float4();
	CHECK(zeroVec.x == 0);
	CHECK(zeroVec.y == 0);
	CHECK(zeroVec.z == 0);
	CHECK(zeroVec.w == 0);
}

TEST_CASE("x y z w is inputed vector constructor")
{
	Float4 v(-2, 0, 1.6, -76.5);
	CHECK(v.x == doctest::Approx(-2).epsilon(0.01));
	CHECK(v.y == doctest::Approx(0).epsilon(0.01));
	CHECK(v.z == doctest::Approx(1.6).epsilon(0.01));
	CHECK(v.w == doctest::Approx(-76.5).epsilon(0.01));
}

TEST_CASE("float[4] vector consturct")
{
	float e[4] = { -1, 0, 3.2, -0.9 };
	Float4 v = Float4(e);

	CHECK(v.x == doctest::Approx(-1).epsilon(0.01));
	CHECK(v.y == doctest::Approx(0).epsilon(0.01));
	CHECK(v.z == doctest::Approx(3.2).epsilon(0.01));
	CHECK(v.w == doctest::Approx(-0.9).epsilon(0.01));
}

TEST_CASE("Float4 vector constuctor")
{
	Float4 v(-3, 0.85, 0, 7.11);
	Float4 w(v);

	CHECK(w.x == doctest::Approx(-3).epsilon(0.01));
	CHECK(w.y == doctest::Approx(0.85).epsilon(0.01));
	CHECK(w.z == doctest::Approx(0).epsilon(0.01));
	CHECK(w.w == doctest::Approx(7.11).epsilon(0.01));
}

TEST_CASE("(Float3, w) is inputed vector constructor")
{
	Float3 v(-2, 0, 1.6);
	double w = -9.33;
	Float4 vec(v, w);

	CHECK(vec.x == doctest::Approx(-2).epsilon(0.01));
	CHECK(vec.y == doctest::Approx(0).epsilon(0.01));
	CHECK(vec.z == doctest::Approx(1.6).epsilon(0.01));
	CHECK(vec.w == doctest::Approx(-9.33).epsilon(0.01));
}

TEST_CASE("Float4 + Float4 calculation")
{
	Float4 v(-2.6, 0.8, 0, 1.2);
	Float4 w(2, 4, -1, -0.845);

	Float4 plus = v + w;
	CHECK(plus.x == doctest::Approx(-0.6).epsilon(0.01));
	CHECK(plus.y == doctest::Approx(4.8).epsilon(0.01));
	CHECK(plus.z == doctest::Approx(-1).epsilon(0.01));
	CHECK(plus.w == doctest::Approx(0.355).epsilon(0.01));
}

TEST_CASE("Float4 - Float4 calculation")
{
	Float4 v(2.6, 0, -.9, 6.11);
	Float4 w(-3, 2, -1, 6.11);

	Float4 minus = v - w;
	CHECK(minus.x == doctest::Approx(5.6).epsilon(0.01));
	CHECK(minus.y == doctest::Approx(-2).epsilon(0.01));
	CHECK(minus.z == doctest::Approx(0.1).epsilon(0.01));
	CHECK(minus.w == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("+Float4 calculation")
{
	Float4 v(-3, 1.6, 0, -.35);

	CHECK(+v.x == doctest::Approx(-3).epsilon(0.01));
	CHECK(+v.y == doctest::Approx(1.6).epsilon(0.01));
	CHECK(+v.z == doctest::Approx(0).epsilon(0.01));
	CHECK(+v.w == doctest::Approx(-0.35).epsilon(0.01));
}

TEST_CASE("+=Float4 calculation")
{
	Float4 a(1, 2, 3, -.5);
	Float4 b(-0.5, 1.6, -3, 0.8);
	Float4 c(0.2, -0.3, 0.4, -1.22);

	a += b += c;
	CHECK(a.x == doctest::Approx(0.7).epsilon(0.01));
	CHECK(a.y == doctest::Approx(3.3).epsilon(0.01));
	CHECK(a.z == doctest::Approx(0.4).epsilon(0.01));
	CHECK(a.w == doctest::Approx(-0.92).epsilon(0.01));

	CHECK(b.x == doctest::Approx(-0.3).epsilon(0.01));
	CHECK(b.y == doctest::Approx(1.3).epsilon(0.01));
	CHECK(b.z == doctest::Approx(-2.6).epsilon(0.01));
	CHECK(b.w == doctest::Approx(-0.42).epsilon(0.01));
}

TEST_CASE("-Float4 calculation")
{
	Float4 v(-3, 16.3, 0, 0.08);

	CHECK(-v.x == doctest::Approx(3).epsilon(0.01));
	CHECK(-v.y == doctest::Approx(-16.3).epsilon(0.01));
	CHECK(-v.z == doctest::Approx(0).epsilon(0.01));
	CHECK(-v.w == doctest::Approx(-0.08).epsilon(0.01));
}

TEST_CASE("-=Float4 calculation")
{
	Float4 a(1, 2, 3, -.5);
	Float4 b(-0.5, 1.6, -3, 0.8);
	Float4 c(0.2, -0.3, 0.4, -1.22);

	a -= b -= c;
	CHECK(a.x == doctest::Approx(1.7).epsilon(0.01));
	CHECK(a.y == doctest::Approx(0.1).epsilon(0.01));
	CHECK(a.z == doctest::Approx(6.4).epsilon(0.01));
	CHECK(a.w == doctest::Approx(-2.52).epsilon(0.01));

	CHECK(b.x == doctest::Approx(-0.7).epsilon(0.01));
	CHECK(b.y == doctest::Approx(1.9).epsilon(0.01));
	CHECK(b.z == doctest::Approx(-3.4).epsilon(0.01));
	CHECK(b.w == doctest::Approx(2.02).epsilon(0.01));
}

TEST_CASE("double * Float4 calculation")
{
	double k = 9.3;
	Float4 v(-3.3, 1, 0, 0.06);

	Float4 val = k * v;
	CHECK(val.x == doctest::Approx(-30.69).epsilon(0.01));
	CHECK(val.y == doctest::Approx(9.3).epsilon(0.01));
	CHECK(val.z == doctest::Approx(0).epsilon(0.01));
	CHECK(val.w == doctest::Approx(0.558).epsilon(0.01));
}

TEST_CASE("Float4 * double calculation")
{
	double k = 9.3;
	Float4 v(-3.3, 1, 0, 0.06);

	Float4 val = v * k;
	CHECK(val.x == doctest::Approx(-30.69).epsilon(0.01));
	CHECK(val.y == doctest::Approx(9.3).epsilon(0.01));
	CHECK(val.z == doctest::Approx(0).epsilon(0.01));
	CHECK(val.w == doctest::Approx(0.558).epsilon(0.01));
}

TEST_CASE("*= Float4 constuctor")
{
	Float4 v(-1, 2, 0.6, 0);
	double k1 = 2.5;
	double k2 = -1.72;

	(v *= k1) *= k2;
	CHECK(v.x == doctest::Approx(4.3).epsilon(0.01));
	CHECK(v.y == doctest::Approx(-8.6).epsilon(0.01));
	CHECK(v.z == doctest::Approx(-2.58).epsilon(0.01));
	CHECK(v.w == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("Float4 / double calculation")
{
	Float4 v(2.1, -6, 0, 0.68);
	double k = 7.7;

	Float4 val = v / k;

	CHECK(val.x == doctest::Approx(2.1 / 7.7).epsilon(0.01));
	CHECK(val.y == doctest::Approx(-6.0 / 7.7).epsilon(0.01));
	CHECK(val.z == doctest::Approx(0).epsilon(0.01));
	CHECK(val.w == doctest::Approx(0.68 / 7.7).epsilon(0.01));
}

TEST_CASE("/= double calculation")
{
	Float4 v(2.1, -6, 0, 0.64);
	double k1 = 7.7;
	double k2 = -1.2;

	(v /= k1) /= k2;
	CHECK(v.x == doctest::Approx(2.1 / 7.7 / -1.2).epsilon(0.01));
	CHECK(v.y == doctest::Approx(-6.0 / 7.7 / -1.2).epsilon(0.01));
	CHECK(v.z == doctest::Approx(0).epsilon(0.01));
	CHECK(v.w == doctest::Approx(0.64 / 7.7 / -1.2).epsilon(0.01));
}

TEST_CASE("Dot() calculation")
{
	Float4 v(2.1, -6, 0, -1.234);
	Float4 w(1, 2, 3, -0.6);

	double dot = Float4::Dot(v, w);
	CHECK(dot == doctest::Approx(-9.1596).epsilon(0.01));
}

TEST_CASE("equal() calculation")
{
	Float4 v(2.1, -6, 0, -1.234);
	Float4 w1(2.1, -6, 0, -1.234);
	float epsilon = 0.01;

	CHECK(v.equal(w1, epsilon));

	Float4 w2(2.08, -6, 0, -1.234);
	CHECK_FALSE(v.equal(w2, epsilon));

	Float4 w3(2.1, -6.02, 0, -1.234);
	CHECK_FALSE(v.equal(w3, epsilon));
}

TEST_CASE("zero() calculation")
{
	Float4 z1 = Float4();
	Float4 z2 = Float4(0.01, 0, 0, 0);
	Float4 z3 = Float4(0, 0.01, 0, 0);
	Float4 z4 = Float4(0, 0, 0.01, 0);
	Float4 z5 = Float4(0, 0, 0, -0.01);

	CHECK(z1.isZero());
	CHECK_FALSE(z2.isZero());
	CHECK_FALSE(z3.isZero());
	CHECK_FALSE(z4.isZero());
	CHECK_FALSE(z5.isZero());
}

TEST_CASE("length() calculation")
{
	Float4 v(2.1, -6, 0, -1.234);
	CHECK(v.length() == doctest::Approx(6.47555063296).epsilon(0.01));
}

TEST_CASE("lengthSq() calculation")
{
	Float4 v(2.1, -6, 0, -1.234);
	CHECK(v.squareLength() == doctest::Approx(41.932756).epsilon(0.01));
}

TEST_CASE("normalize() calculation")
{
	Float4 v(2.1, -6, 0, -1.234);
	v.normalize();
	CHECK(v.x == doctest::Approx(2.1 / 6.47555063296).epsilon(0.01));
	CHECK(v.y == doctest::Approx(-6 / 6.47555063296).epsilon(0.01));
	CHECK(v.z == doctest::Approx(0).epsilon(0.01));
	CHECK(v.w == doctest::Approx(-1.234 / 6.47555063296).epsilon(0.01));
}

TEST_CASE("Normalize() calculation")
{
	Float4 v = Float4::Normalize(Float4(2.1, -6, 0, -1.234));
	CHECK(v.x == doctest::Approx(2.1 / 6.47555063296).epsilon(0.01));
	CHECK(v.y == doctest::Approx(-6 / 6.47555063296).epsilon(0.01));
	CHECK(v.z == doctest::Approx(0).epsilon(0.01));
	CHECK(v.w == doctest::Approx(-1.234 / 6.47555063296).epsilon(0.01));

}