#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265
#include <stdio.h>
#include <math.h>

double distanceKm(double lon1, double lon2, double lat1, double lat2)
{
    return 6378.388 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1));
}

double routeKm(double latitude[], double longitude[])
{
    double distance = 0;

    for (int i = 0; i < 8; i++)
    {
        distance += distanceKm(longitude[i] * (PI / 180.0), longitude[i+1] * (PI / 180.0), latitude[i] * (PI / 180.0), latitude[i+1] * (PI / 180.0));
    }
    return distance;
}

int main()
{
    double latitude[] = { 53.557029, 53.557166, 53.557274, 53.560288, 53.561306, 53.562015, 53.558241, 53.557900, 53.557203 };
    double longitude[] = { 10.022918, 10.021343, 10.020297, 10.014906, 10.015426, 10.016568, 10.023244, 10.022142, 10.022632 };

    printf("Total distance is: %lf ", routeKm(latitude, longitude));

    return 0;
}