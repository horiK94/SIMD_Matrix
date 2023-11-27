#include <iostream>
#include "Test_Float3.h"
#include "Test_Float4.h"
#include "Test_Matrix4.h"
#include "Test_SIMDFloat3.h"
#include "Test_SIMDFloat4.h"
#include "Test_SIMDMatrix.h"

#include <chrono>
#include <vector>

#include <xmmintrin.h>
#include <smmintrin.h>

#define DOCTEST_CONFIG_IMPLEMENT
#include "ThirdParty/doctest/doctest.h"


int main()
{
	//テストの実行
	doctest::Context context;
	context.run();

	SIMDFloat3 v3(1, 2, -3);
	std::cout << v3 << std::endl;

	SIMDFloat4 v4(1, 2, 3, 56);
	std::cout << v4 << std::endl;

	SIMDMatrix4 m4 = SIMDMatrix4::Identity();
	std::cout << m4 << std::endl;
}