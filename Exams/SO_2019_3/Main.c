#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void clearKeyboardBuffer();

int arraySum(int array[], int arraySize);

int main()
{
    int numbers[3];
    printf("Enter three integers formatted x,y,z: ");

    while (1)
    {
        if (scanf("%d,%d,%d", &numbers[0], &numbers[1], &numbers[2]) == 3 &&
            (getchar() == '\n'))
        {
            break;
        }
        else
        {
            printf("Invalid input retry: ");
            clearKeyboardBuffer();
        };
    };

    int sum = arraySum(numbers, 3);
    printf("Sum = %d", sum);
    return 0;
}

void clearKeyboardBuffer()
{
    while (getchar() != '\n');
}

int arraySum(int array[], int arraySize)
{
    int sum;

    if (arraySize > 0) {
        sum = array[arraySize - 1] + arraySum(array, arraySize - 1);
    }
    else
    {
        sum = 0;
    }

    return sum;
}