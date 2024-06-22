/*
Lab exam SoSe 2018.
Lecture: IE-B1-SOL1 (Software construction 1)
*/
#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using functions with potential buffer overflow
#include <stdio.h>
#include <stdbool.h>

/* Function prototypes (provided by examiner) */
double eulerSeries(int);
double factorial(int);

int main() {
	int number;

	bool flag = false;

	printf("Maximum n to use: ");
	while (!flag)
	{
		if (scanf("%d", &number) != 1 || (number < 0)) {
			printf("Invalid input. Retry: ");
			while (getchar() != '\n');
		}
		else
		{
			flag = true;
		}
	}
	while (getchar() != '\n');

	printf("Approx. of Euler's number:\n");
	for (int i = 0; i <= number; i++)
	{
		printf("n = %d: %lf\n", i, eulerSeries(i));
	}

	getchar();
	return 0;
}

double factorial(int m) {
	double fact = 1;

	if (m == 0)
	{
		return 1;
	}
	else 
	{
		for (int i = 1; i <= m; i++)
		{
			fact *= i;
		}
	}

	return fact;
}

double eulerSeries(int n) {
	double e = 0;
	for (int i = 0; i <= n; i++)
	{
		e += 1 / factorial(i);
	}

	return e;
}