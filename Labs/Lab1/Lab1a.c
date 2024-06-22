/* LAB1a - Algorithmic operations for integer numbers | Nikita Barshchevskii
There are two already defined integer numbers, 7 and 3, and the program will do the basic algorithmic operations:
(+, -, *, / and %). Other than that, there's nothing else to explain/add here */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int num1 = 7;                                            // First number
	int num2 = 3;                                            // Second number

	printf("Simple calculator:\n");
	printf("------------------\n");

	printf("1st operand: %d\n", num1);
	printf("2nd operand: %d\n\n", num2);

	printf("%d + %d = %d\n", num1, num2, num1 + num2);       // All of the above mentioned algorithmic operations will be done here
	printf("%d - %d = %d\n", num1, num2, num1 - num2);     
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	printf("%d / %d = %d\n", num1, num2, num1 / num2);
	printf("%d %% %d = %d\n", num1, num2, num1 % num2);

	return 0;
}