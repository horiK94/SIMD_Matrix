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

	using namespace std;

	Float4 a(1, 2, 3, 4);
	Float4 b(-2.5f, 5, -7.5f, 10);

	cout << Float4(Float3(1, 2, 3), -1) << endl;

	cout << (a + b) << endl;
	cout << (a - b) << endl;
	cout << +a << endl;
	cout << -a << endl;
	cout << (a * 0.5) << endl;
	cout << (0.5 * a) << endl;
	cout << (a / 2) << endl;
	cout << (Float4::Dot(a, b)) << endl;
	cout << endl;
	a += b;
	cout << a << endl;
	a -= b;
	cout << a << endl;
	a *= 2;
	cout << a << endl;
	a /= 2;
	cout << a << endl;

	Float4 f = (a += b) += b;
	cout << f << endl;
	cout << endl;
	cout << endl;
}