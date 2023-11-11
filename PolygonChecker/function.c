#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "function.h"

#define pi 3.14

float angleA(float side1, float side2, float side3) {
	float angleA;
	if (side1 >0&&side2>0&&side3>0)
	{
		angleA = acos(((side3 * side3) + (side2 * side2) - (side1 * side1)) / (2 * side2 * side3)) * (180 / pi);
		printf("Angle A: %f%c\n", angleA, 248);
		return angleA;
	}
	else
	{
		angleA = 0;
		return angleA;
	}
}

float angleB(float side1, float side2, float side3) {
	float angleB;
	if (side1 > 0 && side2 > 0 && side3 > 0) {
		angleB = acos(((side1 * side1) + (side3 * side3) - (side2 * side2)) / (2 * side1 * side3)) * (180 / pi);
		printf("Angle B: %f%c\n", angleB, 248);
		return angleB;
	}
	else
	{
		angleB = 0;
		return angleB;
	}
}

float angleC(float side1, float side2, float side3) {
	float angleC;
	if (side1 > 0 && side2 > 0 && side3 > 0)
	{
		angleC = acos(((side2 * side2) + (side1 * side1) - (side3 * side3)) / (2 * side1 * side2)) * (180 / pi);
		printf("Angle C: %f%c\n", angleC, 248);
		return angleC;
	}
	else
	{
		angleC = 0;
		return angleC;
	}
}

char* analyzeTriangle(float side1, float side2, float side3, char result[MAXSIZE]) {
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		printf("Not a triangle\n");
		strncpy(result, "Not a triangle\0", MAXSIZE);
	}
	else if (side1 == side2 && side1 == side3) {
		printf("Equilateral triangle\n");
		strncpy(result, "Equilateral triangle\0", MAXSIZE);
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		printf("Isosceles triangle\n");
		strncpy(result, "Isosceles triangle\0", MAXSIZE);
	}
	else {
		printf("Scalene triangle\n");
		strncpy(result, "Scalene triangle\0", MAXSIZE);
	}

	return result;
}

float perimeter(float side1, float side2, float side3, float side4) {
	float perimeter = side1 + side2 + side3 + side4;
	return perimeter;
}

float area(float side1, float side2) {
	float area = side1 * side2;
	return area;
}

char* analyzeQuadrangle(float side1, float side2, float side3, float side4, char result[MAXSIZE]) {
	if (side1 < 0 || side2<0||side3<0||side4<0)
	{
		printf("Invalid input");
		strcpy(result, "Invalid input\0", MAXSIZE);
	}
	else if (side1 == side3 && side2 == side4)
	{
		strncpy(result, "Rectangle\0", MAXSIZE);
		float Perimeter = perimeter(side1, side2, side3, side4);
		float Area = area(side1, side2);
		printf("The shape is a rectanle\n");
		printf("Perimeter: %f\n", Perimeter);
		printf("Area: %f\n", Area);
	}
	else
	{
		strncpy(result, "Not rectangle\0", MAXSIZE);
		float Perimeter = perimeter(side1, side2, side3, side4);
		printf("Perimeter: %f\n", Perimeter);
	}
}