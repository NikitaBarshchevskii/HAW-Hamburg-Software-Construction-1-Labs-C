#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265
#include <stdio.h>
#include <math.h>

double distanceKm(double lon1, double lon2, double lat1, double lat2)
{
    return 6378.388 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1));
}

double maxDistance(double location[][2], int *imax, int *jmax)
{
    double max = 0;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i != j)
            {
                if (max < distanceKm(location[i][1] * (PI / 180.0), location[j][1] * (PI / 180.0), location[i][0] * (PI / 180.0), location[j][0] * (PI / 180.0)))
                {
                    max = distanceKm(location[i][1] * (PI / 180.0), location[j][1] * (PI / 180.0), location[i][0] * (PI / 180.0), location[j][0] * (PI / 180.0));
                    *imax = i;
                    *jmax = j;
                }
            }
        }
    }

    return max;
}

int main()
{
    int imax = 0, jmax = 0;

    char* names[] = {
         "HAW Hamburg",
         "Eiffel tower",
         "Palma de Mallorca",
         "Las Vegas",
         "Copacabana",
         "Waikiki Beach",
         "Surfers Paradise"
    };

    double location[7][2] = { {53.557078, 10.023109}, {48.858363, 2.294481}, {39.562553, 2.661947}, {36.156214, -115.148736}, {-22.971177, -43.182543}, {21.281004, -157.837456}, {-28.002695, 153.431781} };

    double max = maxDistance(location, &imax, &jmax);

    printf("%s and %s have the largest distance %lf. You'd better not walk. Take a flight instead.", names[imax], names[jmax], max);

    return 0;
}