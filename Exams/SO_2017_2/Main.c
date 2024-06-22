/*
Lab exam winter semester 2017/2018.
Lecture: IE-B1-SOL1 (Software construction 1)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct {
	double real;
	double imag;
} complex;

/* Function prototypes (provided by examiner) */
double absolute(complex z);
complex add(complex a, complex b);
complex multiply(complex a, complex b);

/* Main function (provided by examiner) */
int main(void)
{
	complex z1 = { 3., 4. };
	complex z2 = { 2.0, -1. };
	complex sum, product;

	/* Print complex numbers to the console */
	printf("Input data:\n");
	printf("z1 = %.1f %+.1fj\n", z1.real, z1.imag);
	printf("z2 = %.1f %+.1fj\n", z2.real, z2.imag);

	/* Absolute values */
	printf("\nAbsolute values:\n");
	printf("|z1| = %.3f\n", absolute(z1));
	printf("|z2| = %.3f\n", absolute(z2));

	/* Mathematical operations */
	printf("\nMathematical operations:\n");
	sum = add(z1, z2);
	product = multiply(z1, z2);
	printf("z1 + z2 = %.1f %+.1fj\n", sum.real, sum.imag);
	printf("z1 * z2 = %.1f %+.1fj\n", product.real, product.imag);

	getchar();
	return 0;
}

double absolute(complex z) {
	return (sqrt(pow(z.real, 2) + pow(z.imag, 2)));
}

complex add(complex a, complex b) {
	complex sum;
	sum.real = a.real + b.real;
	sum.imag = a.imag + b.imag;
	return sum;
};

complex multiply(complex a, complex b) {
	complex product;
	product.real = (a.real * b.real - a.imag * b.imag);
	product.imag = (a.real * b.imag + a.imag * b.real);
	return product;
}