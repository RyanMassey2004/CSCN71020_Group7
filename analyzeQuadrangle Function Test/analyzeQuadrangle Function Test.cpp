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
		TEST_METHOD(analyzeQuadrangle1) // Test functionality for rectangle using the same input for each side
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
			float quadrangleSides[4] = { 2,3,4,5 }; // Test functionality for not rectangle using different input for each side
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Not rectangle";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(analyzeQuadrangle3) // Test functionality for invalid input using a negative input for one side
		{
			float quadrangleSides[4] = { -0.99,1,4,5.2 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Invalid input";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(analyzeQuadrangle4) // Test functionality for not rectangle using different decimal input for each side
		{

			float quadrangleSides[4] = { 2.4,1.7,5.1,7.3 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Not rectangle";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(analyzeQuadrangle5) // Test functionality for rectangle using the same decimal input for each side
		{
			float quadrangleSides[4] = { 6.4,6.4,6.4,6.4 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Rectangle";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(analyzeQuadrangle6) // Test functionality for not rectangle using a mix of different inputs
		{
			float quadrangleSides[4] = { 4.2,5.6,2.4,7.9 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Not rectangle";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(analyzeQuadrangle7) // Test functionality for invalid input using a negative decimal input
		{
			float quadrangleSides[4] = { -2.4,1.7,5.1,7.3 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Invalid input";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(analyzeQuadrangle8) // Test functionality for Invalid input using 0 as input for each side
		{
			float quadrangleSides[4] = { 0, 0, 0, 0 };
			float* quadrangleSidesPtr = quadrangleSides;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Invalid input";
			analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
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
			float quadrangleSides[4] = { 0.001,0.001,0.001,0.001 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3]);
			float expected = 0.004;
			Assert::AreEqual(expected, Perimeter);
		}
		TEST_METHOD(perimeterFunc3) 
		{
			float quadrangleSides[4] = { 5.4,5.8,2.4,6.4 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3]);
			float expected = 20;
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
			float quadrangleSides[4] = { 0.01,0.01,0.01,0.01 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Area = area(quadrangleSidesPtr[0], quadrangleSidesPtr[1]);
			float expected = 0.0001;
			Assert::AreEqual(expected, Area);
		}
	};
}