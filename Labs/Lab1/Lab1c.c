/* LAB1c - Digit sum | Nikita Barshchevskii
User will enter his/her birth year and the digits will be counted*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int YearOfBirth, sum = 0; 

	printf("Enter your year of birth: ");      
	scanf_s("%d", &YearOfBirth);
	printf("\n");

	printf("The digit sum of %d is: %d", YearOfBirth, sum = (YearOfBirth % 10) + ((YearOfBirth / 10) % 10) + ((YearOfBirth / 100) % 10) + (YearOfBirth /1000));
    // The complete calculation in one code line
	return 0;
}

    // This code will do exactly the same, just the visual outcome will be as stated in the pdf 

/*  
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>

    int main() {

	  int YearOfBirth, sum = 0, FirstDigit, SecondDigit, ThirdDigit, FourthDigit; 

	  printf("Enter your year of birth: ");
	  scanf_s("%d", &YearOfBirth);
	  printf("\n");
      
	  FirstDigit = YearOfBirth % 10;
	  SecondDigit = (YearOfBirth / 10) % 10;
	  ThirdDigit = (YearOfBirth / 100) % 10;
	  FourthDigit = YearOfBirth / 1000;
	  sum = FirstDigit + SecondDigit + ThirdDigit + FourthDigit;

	  printf("The digit sum of %d is %d + %d + %d + %d = %d", YearOfBirth, FourthDigit, ThirdDigit, SecondDigit, FirstDigit, sum);

	return 0;

	}
*/