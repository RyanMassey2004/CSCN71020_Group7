#include "pch.h"
#include "CppUnitTest.h"

#define MAXSIZE 100

extern "C" char* analyzeQuadrangle(float side1, float side2, float side3, float side4, char result[MAXSIZE]);
extern "C" float area(float side1, float side2);
extern "C" float perimeter(float side1, float side2, float side3, float side4);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace analyzeQuadrangleFunction
{
	TEST_CLASS(analyzeQuadrangleFunction)
	{
	public:
		TEST_METHOD(analyzeQuadrangle1)
		{
			float quadrangleSides[4] = { 2,2,2,2 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Rectangle";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(analyzeQuadrangle2)
		{
			float quadrangleSides[4] = { 2,3,4,5 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Not rectangle";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(analyzeQuadrangle3)
		{
			float quadrangleSides[4] = { -2,1,5,7 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Invalid input";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(analyzeQuadrangle4)
		{
			float quadrangleSides[4] = { 2.4,1.7,5.1,7.3 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Not rectangle";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(analyzeQuadrangle5)
		{
			float quadrangleSides[4] = { 6.4,6.4,6.4,6.4 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Rectangle";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(analyzeQuadrangle6)
		{
			float quadrangleSides[4] = { 5,1,0.00001,7.3 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Not rectangle";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		//Perimeter of rectangle
		TEST_METHOD(perimeterFunc1)
		{
			float quadrangleSides[4] = { 2,2,2,2 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3]);
			float expected = 8;
			Assert::AreEqual(expected, Perimeter);
		}
		TEST_METHOD(perimeterFunc2)
		{
			float quadrangleSides[4] = { 0.999,0.999,0.999,0.999 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3]);
			float expected = 3.996;
			Assert::AreEqual(expected, Perimeter);
		}
		TEST_METHOD(perimeterFunc3)
		{
			float quadrangleSides[4] = { 0.01,3.05,0.9,3.5 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3]);
			float expected = 7.46;
			Assert::AreEqual(expected, Perimeter);
		}
		TEST_METHOD(areaFunc1)
		{
			float quadrangleSides[4] = { 2,2,2,2 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Area = area(quadrangleSidesPtr[0], quadrangleSidesPtr[1]);
			float expected = 4;
			Assert::AreEqual(expected, Area);
		}
		TEST_METHOD(areaFunc2)
		{
			float quadrangleSides[4] = { 2.4,2.4,2.4,2.4 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Area = area(quadrangleSidesPtr[0], quadrangleSidesPtr[1]);
			float expected = 5.76;
			Assert::AreEqual(expected, Area);
		}
		TEST_METHOD(areaFunc3) {
			float quadrangleSides[4] = { 5.456,5.456,5.456,5.456 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Area = area(quadrangleSidesPtr[0], quadrangleSidesPtr[1]);
			float expected = 29.767935;
			Assert::AreEqual(expected, Area);
		}
		TEST_METHOD(areaFunc4) {
			float quadrangleSides[4] = { 0.01,0.01,0.01,0.01 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Area = area(quadrangleSidesPtr[0], quadrangleSidesPtr[1]);
			float expected = 0.000100;
			Assert::AreEqual(expected, Area);
		}
		}
	};
}