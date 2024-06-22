/*
Lab exam winter semester 2016/2017.
Lecture: IE-B1-SO1 (Software construction 1)
*/

#define DIM 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


/* Function prototypes */
void scaleVector2D(double a[DIM], double k);
void printVector2D(double a[DIM]);
double vectorLength(double a[DIM]);
double vectorProduct2D(double a[DIM], double b[DIM]);

/* Main function */
int main(void)
{
	double a1[DIM] = { 3., 4. };
	double a2[DIM] = { -2., 6. };

	/* Print vectors to the console */
	printf("Vectors:\na1 = ");
	printVector2D(a1);
	printf("\na2 = ");
	printVector2D(a2);
	printf("\n\n");

	/* Vector length */
	printf("Vector length:\n||a1|| = %.1f\n\n", vectorLength(a1));

	/* Scale vector */
	scaleVector2D(a2, 0.5);
	printf("Scale a2 with 0.5:\na2 = ");
	printVector2D(a2);
	printf("\n\n");

	///* Vector product */
	printf("Vector product:\n<a1, a2> = %.1f\n\n", vectorProduct2D(a1, a2));

	getchar();
	return 0;
}

void printVector2D(double a[DIM]) {
	printf(" (%.1lf, %.1lf)", a[0], a[1]);
}

double vectorLength(double a[DIM]) {
	return sqrt(pow(a[0], 2) + pow(a[1], 2));
}

void scaleVector2D(double a[DIM], double k) {
	a[0] *= k;
	a[1] *= k;
}

double vectorProduct2D(double a[DIM], double b[DIM]) {
	return (a[0] * b[0] + a[1] * b[1]);
};
