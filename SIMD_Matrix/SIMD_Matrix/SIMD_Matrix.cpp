#include <iostream>
#include "Test_Float3.h"
#include "Test_Float4.h"
#include "Test_Matrix4.h"
#include "Test_SIMDFloat3.h"
#include "Test_SIMDFloat4.h"
#include "Test_SIMDMatrix.h"

#define DOCTEST_CONFIG_IMPLEMENT
#include "ThirdParty/doctest/doctest.h"

int main()
{
	//テストの実行
	doctest::Context context;
	context.run();
}