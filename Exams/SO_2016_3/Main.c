#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/*
Lab exam winter semester 2016/2017.
Lecture: IE-B1-SO1 (Software construction 1)
*/

typedef enum
{
	FALSE = 0,
	TRUE = 1
} boolean;

/* Function prototypes */
int isEven(int);
boolean isPrimeNumber(int);

int main() {
	int lastNumber;
	int primeCount = 0;

	printf("Enter maximum number to test: ");
	bool flag = false;
	while (!flag)
	{
		if (scanf("%d", &lastNumber) == 0 || lastNumber < 0) {
			printf("Try again (expected number >= 0 ): ");
			while (getchar() != '\n');
		}
		else
		{
			flag = true;
		}
	}
	while (getchar() != '\n');

	for (int i = 1; i<= lastNumber; i++)
	{
		if (isPrimeNumber(i) == TRUE) {
			printf("%4d ", i);
			primeCount++;
			if (primeCount % 10 == 0)
			{
				printf("\n");
			}
		}
	}
	printf("\nThere are %d prime numbers in [1, %d].", primeCount, lastNumber);

	return 0;
}

int isEven(int number) {
	return (number % 2) == 0;
}

boolean isPrimeNumber(int k) {
	if (k <= 1 || (isEven(k) == 1 && k >= 4))
	{
		return FALSE;
	}
	else
	{
		for (int m = 3; m < k/2; m+=2)
		{
			if (k % m == 0) {
				return FALSE;
			}
		}
		return TRUE;
	}
}