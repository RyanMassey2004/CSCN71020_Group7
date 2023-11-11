#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "function.h"

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1: {
			char result[MAXSIZE];
			printf_s("Triangle selected.\n");
			float triangleSides[3] = { 0, 0, 0 };
			float* triangleSidesPtr = getTriangleSides(triangleSides);
			analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], result);
			angleA(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			angleB (triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			angleC (triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			break;
		}
		case 2:
		{
			char result[MAXSIZE];
				printf_s("Quadrangle selected.\n");
				float quadrangleSides[4] = { 0, 0, 0,0 };
				float* quadrangleSidesPtr = getQuadrangleSides(quadrangleSides);
				analyzeQuadrangle(quadrangleSidesPtr[0], quadrangleSidesPtr[1], quadrangleSidesPtr[2], quadrangleSidesPtr[3], result);
				break;
			}
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("T\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Quadrangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

float* getTriangleSides(float* triangleSides) {
	printf_s("Enter the three sides of the triangle: \n");
	for (int i = 0; i < 3; i++)
	{
		printf("Side %d: ", i + 1);
		scanf_s("%f", &triangleSides[i]);
	}
	return triangleSides;
}

float* getQuadrangleSides(float* quadrangleSides) {
	printf_s("Enter the four sides of the quadrangle: \n");
	for (int i = 0; i < 4; i++)
	{
		printf("side %d: ", i + 1);
		scanf_s("%f", &quadrangleSides[i]);
	}
	return quadrangleSides;
}