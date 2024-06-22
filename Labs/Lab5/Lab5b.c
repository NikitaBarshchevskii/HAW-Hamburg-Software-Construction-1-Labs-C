#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    double latitude;
    double longitude;
} geoCord;

double dist(double lon1, double lon2, double lat1, double lat2)
{
    lon1 = lon1 * (PI / 180.0);
    lat1 = lat1 * (PI / 180.0);
    lon2 = lon2 * (PI / 180.0);
    lat2 = lat2 * (PI / 180.0);
    return 6378.388 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1));
}


int main()
{
    int n;
    bool flag = false;
    printf("Enter number of waypoints: ");

    while (!flag)
    {
        if (scanf("%d", &n) == 0 || n <= 0) {
            printf("Try again (expected number >= 0 ): ");
            while (getchar() != '\n');
        }
        else
        {
            flag = true;
        }
    }

    /*double* latitudes = (double*)malloc(n * sizeof(double));
    double* longitudes = (double*)malloc(n * sizeof(double));*/

    geoCord* waypoints = (geoCord*)malloc(n * sizeof(geoCord));

    if (waypoints == NULL) {
        printf("Memory allocation failed. Exiting program.\n");

        free(waypoints);

        return 1;
    }

    printf("\nEnter waypoints as \"<latitude> <longitude>\":\n");

    for (int i = 0; i < n; i++) {
        double latitude, longitude;
        int errorCount = 0;
        flag = false;
        printf("Waypoint %d: ", i + 1);

        while (!flag) {
            if (scanf("%lf %lf", &latitude, &longitude) != 2 || latitude < 0 || longitude < 0) {
                if (errorCount == 0)
                {
                    printf("Invalid input (expected \"<latitude> <longitude>\"): ");
                    errorCount++;
                }
                else
                {
                    printf("Try again: ");
                }
                while (getchar() != '\n');
            }
            else {
                waypoints[i].latitude = latitude;
                waypoints[i].longitude = longitude;
                flag = true;
            }
        }

    }

    double totalDist = 0;

    for (int i = 0; i < n - 1; i++)
    {
        totalDist += dist(waypoints[i].longitude, waypoints[i + 1].longitude, waypoints[i].latitude, waypoints[i + 1].latitude);
    }

    free(waypoints);

    printf("\nBy taking this route you will travel %.1lf km", totalDist);

    return 0;
}
