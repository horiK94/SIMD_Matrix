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

#define ANKERL_NANOBENCH_IMPLEMENT
#include "ThirdParty/nanobench/nanobench.h"

void benchFloat4()
{
	ankerl::nanobench::Bench().run("Float4 Not Use SIMD and Use Constuctor", [&] {
		ankerl::nanobench::doNotOptimizeAway([&] {
			Float4 f(1, 2, -3, 0.6);
			f += Float4(0, 2, -3, 0.1);
			});		});
	ankerl::nanobench::Bench().run("Float4 Use SIMD and Use Constuctor", [&] {
		ankerl::nanobench::doNotOptimizeAway([&] {
			SIMDFloat4 f(1, 2, -3, 0.6);
			f += SIMDFloat4(0, 2, -3, 0.1);
			});
		});

	{
		Float4 f(1, 2, -3, 0.6);
		Float4 g(0, 2, -3, 0.1);

		ankerl::nanobench::Bench().run("Float4 Not Use SIMD when plus", [&] {
			f -= g;
			});
	}

	{
		SIMDFloat4 f(1, 2, -3, 0.6);
		SIMDFloat4 g(0, 2, -3, 0.1);

		ankerl::nanobench::Bench().run("Float4 Use SIMD when plus", [&] {
			f -= g;
			});
	}

	{
		Float4 f(1, 2, -3, 0.1);
		float k = 0.6;

		ankerl::nanobench::Bench().minEpochIterations(100000).run("Float4 Not Use SIMD when mul", [&] {
			f *= k;
			});
	}

	{
		SIMDFloat4 f(1, 2, -3, 0.1);
		float k = 0.6;

		ankerl::nanobench::Bench().minEpochIterations(100000).run("Float4 Use SIMD when mul", [&] {
			f *= k;
			});
	}

	{
		Float4 f(1, 2, -3, 0.1);
		float k = 0.7;

		ankerl::nanobench::Bench().run("Float4 Not Use SIMD when div", [&] {
			f /= k;
			});
	}

	{
		SIMDFloat4 f(1, 2, -3, 0.1);
		float k = 0.7;

		ankerl::nanobench::Bench().run("Float4 Use SIMD when div", [&] {
			f /= k;
			});
	}

	{
		Float4 f(1, 2, -3, 0.1);
		Float4 g(0, 2, -3, 0.1);

		ankerl::nanobench::Bench().minEpochIterations(150000000).run("Float4 Not Use SIMD when Dot()", [&] {
			ankerl::nanobench::doNotOptimizeAway([&] {
				Float4::Dot(f, g);
				});
			});
	}

	{
		SIMDFloat4 f(1, 2, -3, 0.1);
		SIMDFloat4 g(0, 2, -3, 0.1);

		ankerl::nanobench::Bench().minEpochIterations(150000000).run("Float4 Use SIMD when Dot()", [&] {
			ankerl::nanobench::doNotOptimizeAway([&] {
				SIMDFloat4::Dot(f, g);
				});
			});
	}

	{
		Float3 f(1, 2, -0.9);
		Float3 g(0, 2, 0.1);

		ankerl::nanobench::Bench().minEpochIterations(100000000).run("Float3 Not Use SIMD when Cross()", [&] {
			ankerl::nanobench::doNotOptimizeAway([&] {
				Float3::Cross(f, g);
				});
			});
	}

	{
		SIMDFloat3 f(1, 2, -0.9);
		SIMDFloat3 g(0, 2, 0.1);

		ankerl::nanobench::Bench().minEpochIterations(100000000).run("Float3 Use SIMD when Cross()", [&] {
			ankerl::nanobench::doNotOptimizeAway([&] {
				SIMDFloat3::Cross(f, g);
				});
			});
	}
}

void benchMatrix4()
{
	ankerl::nanobench::Bench().minEpochIterations(10000000).run("Matrix4 Not Use SIMD and Use Constuctor", [&] {
		ankerl::nanobench::doNotOptimizeAway([&] {
			Matrix4 mat1(
				0, 0, 0, 0,
				2, 1.3, 3.69, 0.6,
				-2.9, -4.3, -3, -6.3,
				0.2, -1.1, 0.6, -0.3
			);
			mat1 += Matrix4(
				2.3, -3.6, 0, 0.9,
				6.3, 0.3, -5.3, -0.1,
				7.1, 0.1, -2.3, -0.1,
				13.1, -5.7, -0.6, -0.3
			);
			});		
		});
	ankerl::nanobench::Bench().minEpochIterations(10000000).run("Matrix4 Use SIMD and Use Constuctor", [&] {
		ankerl::nanobench::doNotOptimizeAway([&] {
			SIMDMatrix4 mat1(
				0, 0, 0, 0,
				2, 1.3, 3.69, 0.6,
				-2.9, -4.3, -3, -6.3,
				0.2, -1.1, 0.6, -0.3
			);
			mat1 += SIMDMatrix4(
				2.3, -3.6, 0, 0.9,
				6.3, 0.3, -5.3, -0.1,
				7.1, 0.1, -2.3, -0.1,
				13.1, -5.7, -0.6, -0.3
			);
			});
		});

	{
		Matrix4 mat1(
			0, 0, 0, 0,
			2, 1.3, 3.69, 0.6,
			-2.9, -4.3, -3, -6.3,
			0.2, -1.1, 0.6, -0.3
		);
		Matrix4 mat2(
			2.3, -3.6, 0, 0.9,
			6.3, 0.3, -5.3, -0.1,
			7.1, 0.1, -2.3, -0.1,
			13.1, -5.7, -0.6, -0.3
		);
		ankerl::nanobench::Bench().run("Matrix4 Not Use SIMD when plus", [&] {
			mat1 -= mat2;
			});
	}

	{
		SIMDMatrix4 mat1(
			0, 0, 0, 0,
			2, 1.3, 3.69, 0.6,
			-2.9, -4.3, -3, -6.3,
			0.2, -1.1, 0.6, -0.3
		);
		SIMDMatrix4 mat2(
			2.3, -3.6, 0, 0.9,
			6.3, 0.3, -5.3, -0.1,
			7.1, 0.1, -2.3, -0.1,
			13.1, -5.7, -0.6, -0.3
		);

		ankerl::nanobench::Bench().run("Matrix4 Use SIMD when plus", [&] {
			mat1 -= mat2;
			});
	}

	{
		Matrix4 mat1(
			0, 0, 0, 0,
			2, 1.3, 3.69, 0.6,
			-2.9, -4.3, -3, -6.3,
			0.2, -1.1, 0.6, -0.3
		);
		Matrix4 mat2(
			2.3, -3.6, 0, 0.9,
			6.3, 0.3, -5.3, -0.1,
			7.1, 0.1, -2.3, -0.1,
			13.1, -5.7, -0.6, -0.3
		);

		ankerl::nanobench::Bench().minEpochIterations(10000000).run("Matrix4 Not Use SIMD when mul", [&] {
			mat1 *= mat2;
			});
	}

	{
		SIMDMatrix4 mat1(
			0, 0, 0, 0,
			2, 1.3, 3.69, 0.6,
			-2.9, -4.3, -3, -6.3,
			0.2, -1.1, 0.6, -0.3
		);
		SIMDMatrix4 mat2(
			2.3, -3.6, 0, 0.9,
			6.3, 0.3, -5.3, -0.1,
			7.1, 0.1, -2.3, -0.1,
			13.1, -5.7, -0.6, -0.3
		);

		ankerl::nanobench::Bench().minEpochIterations(10000000).run("Matrix4 Use SIMD when mul", [&] {
			mat1 *= mat2;
			});
	}

	{
		Matrix4 mat(
			2.3, -3.6, 0, 0.9,
			6.3, 0.3, -5.3, -0.1,
			7.1, 0.1, -2.3, -0.1,
			13.1, -5.7, -0.6, -0.3
		);

		ankerl::nanobench::Bench().minEpochIterations(100000000).run("Matrix4 Not Use SIMD when Det()", [&] {
			ankerl::nanobench::doNotOptimizeAway([&] {
				mat.det();
				});
			});
	}

	{
		SIMDMatrix4 mat(
			2.3, -3.6, 0, 0.9,
			6.3, 0.3, -5.3, -0.1,
			7.1, 0.1, -2.3, -0.1,
			13.1, -5.7, -0.6, -0.3
		);

		ankerl::nanobench::Bench().minEpochIterations(100000000).run("Matrix4 Use SIMD when Det()", [&] {
			ankerl::nanobench::doNotOptimizeAway([&] {
				mat.det();
				});
			});
	}
}

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

	benchFloat4();
	benchMatrix4();
}