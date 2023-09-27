#include <iostream>
#include "Float3.h"
#include "Float4.h"

int main()
{
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

	Float3 c(2, 3, 1);
	Float3 d(-3, 1, 4);

	cout << (c + d) << endl;
	cout << (c - d) << endl;
	cout << +c << endl;
	cout << -c << endl;
	cout << (3 * c) << endl;
	cout << (d / 2) << endl;
	cout << (Float3::Dot(c, d)) << endl;
	cout << (Float3::Cross(c, d)) << endl;
	cout << endl;
	c += d;
	cout << c << endl;
	c -= d;
	cout << c << endl;
	c *= 2;
	cout << c << endl;
	c /= 2;
	cout << c << endl;
	Float3 e = (c += d) += d;
	cout << e << endl;
}