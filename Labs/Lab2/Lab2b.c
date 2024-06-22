// LAB2b - Wheat on chessboard problem | Nikita Barshchevskii
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

    double grains = 1;
    double sum = 0;
    double weight = 0;

    printf("| Field     | On field             | Sum                                      |\n");
    printf("+-----------+----------------------+------------------------------------------+\n");

    for (int i = 1; i <= 64; i++)
    {
        sum += grains;
        int exponent = 0;
        double sumValue = sum;

        while (sumValue >= 10.0)
        {
            sumValue /= 10.0;
            exponent++;
        }

        printf("|%10d |%21.0lf |%28.lf (= %.1lf e+%02d )|\n", i, grains, sum, sumValue, exponent);
        grains *= 2;
    }

    printf("+-----------+----------------------+------------------------------------------+\n\n");

    weight = sum * 0.000000055;
    printf("The overall weight of all wheat grains is %.0lf tons.\n\n", weight);

    printf("Number of bits used on your machine to represent: \n");
    printf("Size for unsigned short: %zu\n", sizeof(unsigned short));
    printf("Size for unsigned: %zu\n", sizeof(unsigned));
    printf("Size for unsigned long: %zu\n", sizeof(unsigned long));
    printf("Size for unsigned long long: %zu\n", sizeof(unsigned long long));

    return 0;
}