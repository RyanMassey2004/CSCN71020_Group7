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

		TEST_METHOD(perimeterOfRectangle)
		{
			float quadrangleSides[4] = { 2,2,2,2 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3]);
			float expected = 8;
			Assert::AreEqual(expected, Perimeter);
		}
		TEST_METHOD(areaOfRectangle)
		{
			float quadrangleSides[4] = { 2,2,2,2 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Area = area(quadrangleSidesPtr[0], quadrangleSidesPtr[1]);
			float expected = 4;
			Assert::AreEqual(expected, Area);
		}

		TEST_METHOD(perimeterOfQuadrangle)
		{
			float quadrangleSides[4] = { 2,3,5,7 };
			float* quadrangleSidesPtr = quadrangleSides;
			float Perimeter = perimeter(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2],quadrangleSidesPtr[3]);
			float expected = 17;
			Assert::AreEqual(expected, Perimeter);
		}
	};
}