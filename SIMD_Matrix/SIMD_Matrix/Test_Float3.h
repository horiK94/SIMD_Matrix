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