#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

#define pi 3.14

float angleA(float side1, float side2, float side3) {
	double angleA = 0;
	angleA = acos(((side3 * side3) + (side2 * side2) - (side1 * side1)) / (2 * side2 * side3)) * (180 / pi);
	printf("Angle A: %f%c\n", angleA,248);
	double angleB = 0;
	angleB = acos(((side1 * side1) + (side3 * side3) - (side2 * side2)) / (2 * side1 * side3)) * (180 / pi);
	printf("Angle B: %lf%c\n", angleB, 248);
	double angleC = 0;
	angleC = acos(((side2 * side2) + (side1 * side1) - (side3 * side3)) / (2 * side1 * side2)) * (180 / pi);
	printf("Angle C: %lf%c\n", angleC, 248);
}

char* analyzeTriangle(float side1, float side2, float side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		printf("Not a triangle\n");
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
		printf("Equilateral triangle\n");
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		printf("Isosceles triangle\n");
		result = "Isosceles triangle";
	}
	else {
		printf("Scalene triangle\n");
		result = "Scalene triangle";
	}

	return result;
}

float analyzeQuadrangle(float side1, float side2, float side3, float side4, float perimeter, float area) {
	if (side1 == side3 && side2 == side4)
	{
		perimeter = side1 + side2 + side3 + side4;
		area = side1 * side2;
		printf("The shape is a rectangle\n");
		printf("Perimeter: %f\n", perimeter);
		printf("Area: %f\n", area);
	}
	else
	{
		perimeter = side1 + side2 + side3 + side4;
		printf("Perimeter: %f\n", perimeter);
	}
}