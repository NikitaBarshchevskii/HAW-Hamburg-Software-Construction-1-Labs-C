/*
Lab exam winter semester 2017/2018.
Lecture: IE-B1-SOL1 (Software construction 1)
*/

#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using functions with potential buffer overflow
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Function prototypes (provided by examiner) */
void sortDescending(int* a, int* b);
int greatestCommonDivisor(int, int);
int getNumberOfDivisors(int m);
int* newArrayOfDivisors(int m);

int main() {
	int number1, number2;
	bool flag = false;

	printf("Enter two positive integer numbers (comma-separated): ");
	while (!flag)
	{
		if (scanf("%d,%d", &number1, &number2) != 2 || (number1 <= 0) || (number2 <= 0)) {
			printf("Invalid input. Retry: ");
			while (getchar() != '\n');
		}
		else
		{
			flag = true;
		}
	}
	while (getchar() != '\n');

	int n = getNumberOfDivisors(number1);
	int* divisors;
	divisors = newArrayOfDivisors(number1);
	int gcd = greatestCommonDivisor(number1, number2);

	printf("Divisors of %d:", number1);
	for (int i = 0; i < n; i++)
	{
		printf(" %d", divisors[i]);
	}
	printf("\n");

	printf("Greatest common devisor: gcd(%d, %d) = %d", number1, number2, greatestCommonDivisor(number1, number2));
	getchar();

	return 0;
}

void sortDescending(int* a, int* b) {
	int buffer;
	if (*a < *b) {
		buffer = *b;
		*b = *a;
		*a = buffer;
	}
}

int greatestCommonDivisor(int m, int n) {
	int r;

	do
	{
		sortDescending(&m, &n);
		r = m % n;
		m = r;
	} while (r != 0);

	return n;
}

int getNumberOfDivisors(int m) {
	int count = 0;

	for (int i = 1; i < m; i++)
	{
		if (m % i == 0) 
		{
			count++;
		}
	}
	
	return count;
}

int* newArrayOfDivisors(int m) {
	int n = getNumberOfDivisors(m);
	int* divisors = (int*)malloc(n * sizeof(int));
	if (divisors == NULL) {
		printf("Memory allocation failed. Exiting program.\n");
	}
	int arrIterator = 0;

	for (int i = 1; i < m; i++)
	{
		if (m % i == 0)
		{
			divisors[arrIterator++] = i;
		}
	}

	return divisors;
}
