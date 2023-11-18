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
		//Perimeter of rectangle
		TEST_METHOD(perimeterOfRectangle1)
		{
			float quadrangleSides[4] = { 2,2,2,2 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3]);
			float expected = 8;
			Assert::AreEqual(expected, Perimeter);
		}
		TEST_METHOD(perimeterOfRectangle2)
		{
			float quadrangleSides[4] = { 5.1,3.7,2.8,1.4 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3]);
			float expected = 13;
			Assert::AreEqual(expected, Perimeter);
		}
		TEST_METHOD(perimeterOfRectangle3)
		{
			float quadrangleSides[4] = { 0.01,0.01,0.01,0.01 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3]);
			float expected = 0.04;
			Assert::AreEqual(expected, Perimeter);
		}
		//Area of rectangle
		TEST_METHOD(areaOfRectangle1)
		{
			float quadrangleSides[4] = { 2,2,2,2 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Area = area(quadrangleSidesPtr[0], quadrangleSidesPtr[1]);
			float expected = 4;
			Assert::AreEqual(expected, Area);
		}
		TEST_METHOD(areaOfRectangle2)
		{
			float quadrangleSides[4] = { 3.4,3.4,3.4,3.4 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Area = area(quadrangleSidesPtr[0], quadrangleSidesPtr[1]);
			float expected = 11.56;
			Assert::AreEqual(expected, Area);
		}
		TEST_METHOD(areaOfRectangle3)
		{
			float quadrangleSides[4] = { 0.01,0.01,0.01,0.01 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Area = area(quadrangleSidesPtr[0], quadrangleSidesPtr[1]);
			float expected = 0.0001;
			Assert::AreEqual(expected, Area);
		}
		//Perimeter of quadrangle
		TEST_METHOD(perimeterOfQuadrangle1)
		{
			float quadrangleSides[4] = { 2,3,5,7 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2],quadrangleSidesPtr[3]);
			float expected = 17;
			Assert::AreEqual(expected, Perimeter);
		}
		TEST_METHOD(perimeterOfQuadrangle2)
		{
			float quadrangleSides[4] = { 0.01,3.05,0.9,3.5 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3]);
			float expected = 7.46;
			Assert::AreEqual(expected, Perimeter);
		}
	};
}