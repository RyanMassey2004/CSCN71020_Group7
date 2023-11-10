#include "pch.h"
#include "CppUnitTest.h"

#define MAXSIZE 100

extern "C" char* analyzeTriangle(float side1, float side2, float side3, char result[MAXSIZE]);
extern "C" float angleA(float side1, float side2, float side3);
extern "C" float angleB(float side1, float side2, float side3);
extern "C" float angleC(float side1, float side2, float side3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace analyzeTriangleFunction
{
	TEST_CLASS(analyzeTriangleFunction)
	{
	public:
		TEST_METHOD(typeOfTriangle1)
		{
			float triangleSlide[3] = { 2,2,2 };
			float* triangleSidesPtr = triangleSlide;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Equilateral triangle";
			analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(typeOfTriangle2)
		{
			float triangleSlide[3] = { -2,2,2 };
			float* triangleSidesPtr = triangleSlide;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Not a triangle";
			analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(typeOfTriangle3)
		{
			float triangleSlide[3] = { 2,2,4 };
			float* triangleSidesPtr = triangleSlide;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Isosceles triangle";
			analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(typeOfTriangle4)
		{
			float triangleSlide[3] = { 3,5,3 };
			float* triangleSidesPtr = triangleSlide;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Isosceles triangle";
			analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		TEST_METHOD(typeOfTriangle5)
		{
			float triangleSlide[3] = { 3,5,7 };
			float* triangleSidesPtr = triangleSlide;
			char result[MAXSIZE];
			char expected[MAXSIZE] = "Scalene triangle";
			analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], result);
			int cmp = strcmp(result, expected);
			Assert::AreEqual(0, cmp);
		}
		//Test for the 3 angles results of Equilateral triangle 
		TEST_METHOD(angle1OfEquilateralTriangle)
		{
			float triangleSlide[3] = { 3,3,3 };
			float* triangleSidesPtr = triangleSlide;
			float angle1 = angleA(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			float expected = 60.030434;

			Assert::AreEqual(expected, angle1);

		}
		TEST_METHOD(angle2OfEquilateralTriangle)
		{
			float triangleSlide[3] = { 3,3,3 };
			float* triangleSidesPtr = triangleSlide;
			float angle2 = angleB(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			float expected = 60.030434;

			Assert::AreEqual(expected, angle2);
		}
		TEST_METHOD(angles3OfEquilateralTriangle)
		{
			float triangleSlide[3] = { 3,3,3 };
			float* triangleSidesPtr = triangleSlide;
			float angle2 = angleB(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			float expected = 60.030434;

			Assert::AreEqual(expected, angle2);
		}
		//Test for the 3 angles results of Isosceles triangle 
		TEST_METHOD(angles1OfIsoscelesTriangle)
		{
			float triangleSlide[3] = { 3,5,3 };
			float* triangleSidesPtr = triangleSlide;
			float angle1 = angleA(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			float expected = 33.574333;
			Assert::AreEqual(expected, angle1);
		}
		TEST_METHOD(angles2OfIsoscelesTriangle)
		{
			float triangleSlide[3] = { 3,5,3 };
			float* triangleSidesPtr = triangleSlide;
			float angle2 = angleB(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			float expected = 112.942635;
			Assert::AreEqual(expected, angle2);
		}
		TEST_METHOD(angles3OfIsoscelesTriangle)
		{
			float triangleSlide[3] = { 3,5,3 };
			float* triangleSidesPtr = triangleSlide;
			float angle3 = angleC(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			float expected = 33.574333;
			Assert::AreEqual(expected, angle3);
		}
		//Test for the 3 angles results of Scalene triangle
		TEST_METHOD(angles1OfScaleneTriangle)
		{
			float triangleSlide[3] = { 3,5,7 };
			float* triangleSidesPtr = triangleSlide;
			float angle1 = angleA(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			float expected = 21.797844;
			Assert::AreEqual(expected, angle1);
		}
		TEST_METHOD(angles2OfScaleneTriangle)
		{
			float triangleSlide[3] = { 3,5,7 };
			float* triangleSidesPtr = triangleSlide;
			float angle2 = angleB(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			float expected = 38.232594;
			Assert::AreEqual(expected, angle2);
		}
		TEST_METHOD(angles3OfScaleneTriangle)
		{
			float triangleSlide[3] = { 3,5,7 };
			float* triangleSidesPtr = triangleSlide;
			float angle3 = angleC(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			float expected = 120.060867;
			Assert::AreEqual(expected, angle3);
		}
	};
}