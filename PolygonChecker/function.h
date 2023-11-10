#pragma once
#define MAXSIZE 100
char* analyzeTriangle(float side1, float side2, float side3, char result[MAXSIZE]);
float angleA(float side1, float side2, float side3);
float angleB(float side1, float side2, float side3);
float angleC(float side1, float side2, float side3);
char* analyzeQuadrangle(float side1, float side2, float side3, float side4, char result[MAXSIZE]);
float perimeter(float side1, float side2, float side3, float side4);
float area(float side1, float side2);