#include <iostream>
#include "Test_Float3.h"
#include "Test_Float4.h"
#include "Test_Matrix4.h"
#include "Test_SIMDFloat3.h"
#include "Test_SIMDFloat4.h"
#include "Test_SIMDMatrix.h"

#include <chrono>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT
#include "ThirdParty/doctest/doctest.h"

//#define RUN_COUNT 1000000

void measureRunTime()
{
	std::chrono::system_clock::time_point start, end;

	//{
	//	//Float3
	//	double timeWithoutSIMD = 0;
	//	{
	//		Float3 a(2, 3, 1);
	//		Float3 b(-3, 1, 4);

	//		start = std::chrono::system_clock::now();
	//		for (int i = 0; i < RUN_COUNT; i++)
	//		{
	//			a += b;
	//			a -= b;
	//			Float3::Dot(a, b);
	//		}
	//		end = std::chrono::system_clock::now();
	//		timeWithoutSIMD = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
	//		std::cout << "Float3 time: " << timeWithoutSIMD << std::endl;
	//	}

	//	{
	//		SIMDFloat3 a(2, 3, 1);
	//		SIMDFloat3 b(-3, 1, 4);

	//		start = std::chrono::system_clock::now();
	//		for (int i = 0; i < RUN_COUNT; i++)
	//		{
	//			a += b;
	//			a -= b;
	//			SIMDFloat3::Dot(a, b);
	//		}
	//		end = std::chrono::system_clock::now();
	//		double timeUseSIMD = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
	//		std::cout << "SIMDFloat3 time: " << timeUseSIMD << std::endl;
	//		std::cout << "diff: " << (timeWithoutSIMD - timeUseSIMD) << std::endl;
	//		std::cout << std::endl;
	//	}
	//}

	//{
	//	//Float4
	//	double timeWithoutSIMD = 0;
	//	{
	//		Float4 a(1, 2, 3, 4);
	//		Float4 b(-2.5f, 5, -7.5f, 10);

	//		std::vector<Float4> v(RUN_COUNT);
	//		std::vector<float> n(RUN_COUNT);

	//		start = std::chrono::system_clock::now();
	//		for (int i = 0; i < RUN_COUNT; i++)
	//		{
	//			//v.push_back(a + b);
	//			//n.push_back(Float4::Dot(a, b));
	//		}
	//		end = std::chrono::system_clock::now();
	//		timeWithoutSIMD = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
	//		std::cout << "Float4 time: " << timeWithoutSIMD << std::endl;
	//	}

	//	{
	//		SIMDFloat4 a(1, 2, 3, 4);
	//		SIMDFloat4 b(-2.5f, 5, -7.5f, 10);

	//		std::vector<SIMDFloat4> v(RUN_COUNT);
	//		std::vector<float> n(RUN_COUNT);

	//		start = std::chrono::system_clock::now();
	//		for (int i = 0; i < RUN_COUNT; i++)
	//		{
	//			//v.push_back(a + b);
	//			//n.push_back(SIMDFloat4::Dot(a, b));
	//		}
	//		end = std::chrono::system_clock::now();
	//		double timeUseSIMD = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
	//		std::cout << "SIMDFloat4 time: " << timeUseSIMD << std::endl;
	//		std::cout << "diff: " << (timeWithoutSIMD - timeUseSIMD) << std::endl;
	//		std::cout << std::endl;
	//	}
	//}

	//{
	//	//Matrix4
	//	double timeWithoutSIMD = 0;
	//	{
	//		Matrix4 m1 = Matrix4(
	//			0, 0, 0, 0,
	//			2, 1.3, 3.69, 0.6,
	//			-2.9, -4.3, -3, -6.3,
	//			0.2, -1.1, 0.6, -0.3
	//		);
	//		Matrix4 m2 = Matrix4(
	//			2.3, -3.6, 0, 0.9,
	//			6.3, 0.3, -5.3, -0.1,
	//			7.1, 0.1, -2.3, -0.1,
	//			13.1, -5.7, -0.6, -0.3
	//		);

	//		start = std::chrono::system_clock::now();
	//		for (int i = 0; i < RUN_COUNT; i++)
	//		{
	//			m1 *= m2;
	//		}
	//		end = std::chrono::system_clock::now();
	//		timeWithoutSIMD = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
	//		std::cout << "Matrix4 time: " << timeWithoutSIMD << std::endl;
	//	}

	//	{
	//		SIMDMatrix4 m1 = SIMDMatrix4(
	//			0, 0, 0, 0,
	//			2, 1.3, 3.69, 0.6,
	//			-2.9, -4.3, -3, -6.3,
	//			0.2, -1.1, 0.6, -0.3
	//		);
	//		SIMDMatrix4 m2 = SIMDMatrix4(
	//			2.3, -3.6, 0, 0.9,
	//			6.3, 0.3, -5.3, -0.1,
	//			7.1, 0.1, -2.3, -0.1,
	//			13.1, -5.7, -0.6, -0.3
	//		);

	//		start = std::chrono::system_clock::now();
	//		for (int i = 0; i < RUN_COUNT; i++)
	//		{
	//			m1 *= m2;
	//		}
	//		end = std::chrono::system_clock::now();
	//		double timeUseSIMD = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
	//		std::cout << "SIMDMatrix4 time: " << timeUseSIMD << std::endl;
	//		std::cout << "diff: " << (timeWithoutSIMD - timeUseSIMD) << std::endl;
	//		std::cout << std::endl;
	//	}
	//}
}

int main()
{
	//テストの実行
	doctest::Context context;
	context.run();

	//実行時間の計測
	measureRunTime();
}