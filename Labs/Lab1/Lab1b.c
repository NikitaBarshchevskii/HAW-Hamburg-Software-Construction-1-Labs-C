/* LAB1b - Algorithmic operations for integer numbers | Nikita Barshchevskii
The user will now input the two numbers of choice and the basic algorithmic operations will run*/ 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int num1, num2;

	printf("Simple calculator:\n");
	printf("------------------\n");

	printf("1st operand: ");
	scanf_s("%d", &num1);                                  // User inputting the first number
	printf("2nd operand: ");
	scanf_s("%d", &num2);                                  // User inputting the second number
	printf("\n");

	printf("%d + %d = %d\n", num1, num2, num1 + num2);     // Basic algorithmic operations here
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	printf("%d / %d = %d\n", num1, num2, num1 / num2);
	printf("%d %% %d = %d\n", num1, num2, num1 % num2);

	return 0;
}