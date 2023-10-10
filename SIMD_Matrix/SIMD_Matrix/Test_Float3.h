#pragma once
#include "Float3.h"
#include "ThirdParty/doctest/doctest.h"

TEST_CASE("zero vector construct")
{
	Float3 zeroVec = Float3();
	CHECK(zeroVec.x == 0);
	CHECK(zeroVec.y == 0);
	CHECK(zeroVec.z == 0);
}

TEST_CASE("x y z is inputed vector constructor")
{
	Float3 v(-2, 0, 1.6);
	CHECK(v.x == doctest::Approx(-2).epsilon(0.01));
	CHECK(v.y == doctest::Approx(0).epsilon(0.01));
	CHECK(v.z == doctest::Approx(1.6).epsilon(0.01));
}

TEST_CASE("float[3] vector consturct")
{
	float e[3] = {-1, 0, 3.2};
	Float3 v = Float3(e);

	CHECK(v.x == doctest::Approx(-1).epsilon(0.01));
	CHECK(v.y == doctest::Approx(0).epsilon(0.01));
	CHECK(v.z == doctest::Approx(3.2).epsilon(0.01));
}

TEST_CASE("Float3 vector constuctor")
{
	Float3 v(-3, 0.85, 0);
	Float3 w(v);

	CHECK(w.x == doctest::Approx(-3).epsilon(0.01));
	CHECK(w.y == doctest::Approx(0.85).epsilon(0.01));
	CHECK(w.z == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("Float3 + Float3 calculation")
{
	Float3 v(-2.6, 0.8, 0);
	Float3 w(2, 4, -1);

	Float3 plus = v + w;
	CHECK(plus.x == doctest::Approx(-0.6).epsilon(0.01));
	CHECK(plus.y == doctest::Approx(4.8).epsilon(0.01));
	CHECK(plus.z == doctest::Approx(-1).epsilon(0.01));
}

TEST_CASE("Float3 - Float3 calculation")
{
	Float3 v(2.6, 0, -.9);
	Float3 w(-3, 2, -1);

	Float3 minus = v - w;
	CHECK(minus.x == doctest::Approx(5.6).epsilon(0.01));
	CHECK(minus.y == doctest::Approx(-2).epsilon(0.01));
	CHECK(minus.z == doctest::Approx(0.1).epsilon(0.01));
}

TEST_CASE("+Float3 calculation")
{
	Float3 v(-3, 1.6, 0);

	CHECK(+v.x == doctest::Approx(-3).epsilon(0.01));
	CHECK(+v.y == doctest::Approx(1.6).epsilon(0.01));
	CHECK(+v.z == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("+=Float3 calculation")
{
	Float3 a(1, 2, 3);
	Float3 b(-0.5, 1.6, -3);
	Float3 c(0.2, -0.3, 0.4);

	a += b += c;
	CHECK(a.x == doctest::Approx(0.7).epsilon(0.01));
	CHECK(a.y == doctest::Approx(3.3).epsilon(0.01));
	CHECK(a.z == doctest::Approx(0.4).epsilon(0.01));

	CHECK(b.x == doctest::Approx(-0.3).epsilon(0.01));
	CHECK(b.y == doctest::Approx(1.3).epsilon(0.01));
	CHECK(b.z == doctest::Approx(-2.6).epsilon(0.01));
}

TEST_CASE("-Float3 calculation")
{
	Float3 v(-3, 16.3, 0);

	CHECK(-v.x == doctest::Approx(3).epsilon(0.01));
	CHECK(-v.y == doctest::Approx(-16.3).epsilon(0.01));
	CHECK(-v.z == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("-=Float3 calculation")
{
	Float3 a(1, 2, 3);
	Float3 b(-0.5, 1.6, -3);
	Float3 c(0.2, -0.3, 0.4);

	a -= b -= c;
	CHECK(a.x == doctest::Approx(1.7).epsilon(0.01));
	CHECK(a.y == doctest::Approx(0.1).epsilon(0.01));
	CHECK(a.z == doctest::Approx(6.4).epsilon(0.01));

	CHECK(b.x == doctest::Approx(-0.7).epsilon(0.01));
	CHECK(b.y == doctest::Approx(1.9).epsilon(0.01));
	CHECK(b.z == doctest::Approx(-3.4).epsilon(0.01));
}

TEST_CASE("double * Float3 calculation")
{
	double k = 9.3;
	Float3 v(-3.3, 1, 0);

	Float3 val = k * v;
	CHECK(val.x == doctest::Approx(-30.69).epsilon(0.01));
	CHECK(val.y == doctest::Approx(9.3).epsilon(0.01));
	CHECK(val.z == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("Float3 * double calculation")
{
	double k = 9.3;
	Float3 v(-3.3, 1, 0);

	Float3 val = v * k;
	CHECK(val.x == doctest::Approx(-30.69).epsilon(0.01));
	CHECK(val.y == doctest::Approx(9.3).epsilon(0.01));
	CHECK(val.z == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("*= Float3 constuctor")
{
	Float3 v(-1, 2, 0.6);
	double k1 = 2.5;
	double k2 = -1.72;

	(v *= k1) *= k2;
	CHECK(v.x == doctest::Approx(4.3).epsilon(0.01));
	CHECK(v.y == doctest::Approx(-8.6).epsilon(0.01));
	CHECK(v.z == doctest::Approx(-2.58).epsilon(0.01));
}

TEST_CASE("Float3 / double calculation")
{
	Float3 v(2.1, -6, 0);
	double k = 7.7;

	Float3 val = v / k;

	CHECK(val.x == doctest::Approx(2.1 / 7.7).epsilon(0.01));
	CHECK(val.y == doctest::Approx(-6.0 / 7.7).epsilon(0.01));
	CHECK(val.z == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("/= double calculation")
{
	Float3 v(2.1, -6, 0);
	double k1 = 7.7;
	double k2 = -1.2;

	(v /= k1) /= k2;
	CHECK(v.x == doctest::Approx(2.1 / 7.7 / -1.2).epsilon(0.01));
	CHECK(v.y == doctest::Approx(-6.0 / 7.7 / -1.2).epsilon(0.01));
	CHECK(v.z == doctest::Approx(0).epsilon(0.01));
}

TEST_CASE("Dot() calculation")
{
	Float3 v(2.1, -6, 0);
	Float3 w(1, 2, 3);

	double dot = Float3::Dot(v, w);
	CHECK(dot == doctest::Approx(-9.9).epsilon(0.01));
}

TEST_CASE("Cross() calculation")
{
	Float3 v(2.1, -6, 0);
	Float3 w(1, 2, 3);

	Float3 cross = Float3::Cross(v, w);
	CHECK(cross.x == doctest::Approx(-18).epsilon(0.01));
	CHECK(cross.y == doctest::Approx(-6.3).epsilon(0.01));
	CHECK(cross.z == doctest::Approx(10.2).epsilon(0.01));
}