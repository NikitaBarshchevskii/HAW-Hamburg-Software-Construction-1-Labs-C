#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265
#include <stdio.h>
#include <math.h>

struct geoCoord {
	double latitude;
	double longitude;
};

double distanceKm(double lon1, double lon2, double lat1, double lat2)
{
	return 6378.388 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1));
}

double routeKm(struct geoCoord coordinates[], int waypoints)
{
	double distance = 0;

	for (int i = 0; i < waypoints - 1; i++)
	{
		distance += distanceKm(coordinates[i].longitude * (PI / 180.0), coordinates[i + 1].longitude* (PI / 180.0), coordinates[i].latitude * (PI / 180.0), coordinates[i + 1].latitude * (PI / 180.0));
	}
	return distance;
}

int main()
{
	int waypoints;

	do
	{
		printf("Enter the number of waypoints: ");

		if (scanf_s("%d", &waypoints) == 1)
		{
			if (waypoints >= 2)
			{
				break;
			}
			else
			{
				printf("Invalid input. You need at least two waypoints.\n");
			}
		}
		else
		{
			printf("Invalid input. Please try again.\n");
			while (getchar() != '\n');
		}

	} while (1);

	// double latitude[sizeof(waypoints)];
	// double longitude[sizeof(waypoints)];

	// double* latitude = (double*)malloc(waypoints * sizeof(double));
	// double* longitude = (double*)malloc(waypoints * sizeof(double));

	struct geoCoord* coordinates = (struct geoCoord*)malloc(waypoints * sizeof(struct geoCoord));

	printf("\n");
	printf("Enter waypoints as latitude and longitude: \n");

	for (int i = 0; i < waypoints; i++)
	{
		printf("Waypoint %d: ", i + 1);

		do
		{
			if (scanf_s("%lf %lf", &coordinates[i].latitude, &coordinates[i].longitude) == 2)
			{
				break;
			}
			else
			{
				printf("Invalid input. Please enter correct latitude and/or longitude.\n");
				while (getchar() != '\n');
				printf("Waypoint %d: ", i + 1);
			}
		} while (1);
	}

	printf("\n");
	printf("By taking this route you will travel %.3lf km.", routeKm(coordinates, waypoints));

	// free(latitude);
	// free(longitude);

	free(coordinates);

	return 0;
}