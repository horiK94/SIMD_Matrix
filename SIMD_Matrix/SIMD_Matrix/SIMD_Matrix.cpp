#include <iostream>
#include "Float3.h"
#include "Test_Float3.h"
#include "Float4.h"

#define DOCTEST_CONFIG_IMPLEMENT
#include "ThirdParty/doctest/doctest.h"

int main()
{
	//テストの実行
	doctest::Context context;
	context.run();
}