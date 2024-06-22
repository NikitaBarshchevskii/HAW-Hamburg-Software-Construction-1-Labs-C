// LAB3b - Distances | Nikita Barshchevskii
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265
#include <stdio.h>
#include <math.h>

double calcY(double lat1, double lat2)
{
    return 111.3 * fabs(lat1 - lat2);
}

double calcX(double lon1, double lon2, double lat1, double lat2)
{
    return 111.3 * cos((lat1 * (PI / 180.0) + lat2 * (PI / 180.0)) / 2.0) * fabs(lon1 - lon2);
}

double localDistanceKm(double x, double y)
{
    return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

double distanceKm(double lon1, double lon2, double lat1, double lat2)
{
    return 6378.388 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1));
}

int main() {

    // double lat1 = 53.557078, lon1 = 10.023109, lat2, lon2;

    double lat1, lon1, lat2, lon2;

    printf("Enter the latitude of location 1: ");
    scanf_s("%lf", &lat1);

    printf("Enter the longitude of location 1: ");
    scanf_s("%lf", &lon1);

    printf("Enter the latitude of location 2: ");
    scanf_s("%lf", &lat2);

    printf("Enter the longitude of location 2: ");
    scanf_s("%lf", &lon2);

    printf("\n");
    printf("Local distance to HAW [km]: %lf\n\n", localDistanceKm(calcX(lon1, lon2, lat1, lat2), calcY(lat1, lat2)));

    lon1 = lon1 * (PI / 180.0);
    lat1 = lat1 * (PI / 180.0);
    lon2 = lon2 * (PI / 180.0);
    lat2 = lat2 * (PI / 180.0);

    printf("Distance to HAW [km]: %lf\n", distanceKm(lon1, lon2, lat1, lat2));

    return 0;
}

/* 
    | Location           |  Latitude   |  Longitude   |  Distance to HAW  |  Local Distance to HAW  |
    _________________________________________________________________________________________________
       
    | HAW Hamburg        |  53.557078  |  10.023109   |    0.0            |    0.0                  |

    | Eiffel Tower       |  48.858363  |  2.294481    |    750.3          |    750.9                |

    | Palma de Mallorca  |  39.562553  |  2.661947    |    1654.541892    |    1656.335613          |

    | Las Vegas          |  36.156214  | -115.148736  |    8745.613228    |    10063.875376         |

    | Copacabana         | -22.971177  | -43.182543   |    9932.259406    |    10255.607346         |

    | Waikiki Beach      |  21.281004  | -157.837456  |    11625.376640   |    15266.841621         |

    | Surfer’s Paradise  | -28.002695  |  153.431781  |    15921.119832   |    18019.645260         |

*/