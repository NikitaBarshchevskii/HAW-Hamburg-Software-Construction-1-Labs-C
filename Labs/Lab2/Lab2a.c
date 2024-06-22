// LAB2a - Chessboard fields | Nikita Barshchevskii
// Using a for loop, we will create something that looks like chessboard fields

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int row = 8;
	char column = 'a';

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%c%d ", column, row);
			column++;
		}
		printf("\n");
		column = 'a';
		row--;
	}

	return 0;

}

// This is slightly modified code that will output the same chessboard fields, but they'll look exactly like in pdf

/*
   #define _CRT_SECURE_NO_WARNINGS
   #include <stdio.h>

   int main() {
  
    int row = 8;
    char column = 'a';

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("+----");
        }

        printf("+\n");

        for (int j = 0; j < 8; j++)
        {
            printf("| %c%d ", column, row);
            column++;
        }

        printf("|\n");
        row--;
        column = 'a';
    }

    for (int j = 0; j < 8; j++)
    {
        printf("+----");
    }

    printf("+\n");

    return 0;
   
   }

*/

