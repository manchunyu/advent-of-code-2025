#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    long x;
    long y;
} Coord;

typedef struct {
    Coord* coords;
    int size;
    int capacity;
} CoordArray;

long calcArea(Coord coord1, Coord coord2);
bool isValid(Coord coord1, Coord coord2, CoordArray coordArr);

int main(void)
{
    CoordArray coordArr = {
        .coords = NULL,
        .size = 0,
        .capacity = 200000,
    };

    coordArr.coords = malloc(sizeof(Coord) * coordArr.capacity);
    if (NULL == coordArr.coords)
    {
        return 1;
    }

    char rowBuffer[256];
    long maxAreaFound = 0;
    while (NULL != fgets(rowBuffer, sizeof(rowBuffer), stdin))
    {
        Coord coord;
        sscanf(rowBuffer, "%ld,%ld", &coord.x, &coord.y);
        printf("x: %li, y: %li\n", coord.x, coord.y);
        // for (int i = 0; i < coordArr.size; i++)
        // {
        //     long area = calcArea(coord, coordArr.coords[i]);
        //     printf("%li\n", area);
        //     if (area > maxAreaFound)
        //     {
        //         maxAreaFound = area;
        //     }
        // }
        coordArr.coords[coordArr.size++] = coord;
    }

    for (int i = 0; i < coordArr.size; i++)
    {
        for (int j = i + 1; j < coordArr.size; j++)
        {
            if (isValid(coordArr.coords[j], coordArr.coords[i], coordArr))
            {
                long area = calcArea(coordArr.coords[j], coordArr.coords[i]);
                printf("Coord1: %li,%li, Coord2 %li, %li Area: %li\n", coordArr.coords[i].x, coordArr.coords[i].y, coordArr.coords[j].x, coordArr.coords[j].y, area);
                if (area > maxAreaFound)
                {
                    maxAreaFound = area;
                }
            }
        }
    }

    printf("Max Area: %li\n", maxAreaFound);
}

long calcArea(Coord coord1, Coord coord2)
{
    return ((labs(coord1.x - coord2.x) + 1) * (labs(coord1.y - coord2.y) + 1));
}

bool isValid(Coord coord1, Coord coord2, CoordArray coordArr)
{
    Coord coordTocheck1 = {
        .x = coord1.x,
        .y = coord2.y,
    };

    Coord coordToCheck2 = {
        .x = coord2.x,
        .y = coord1.y,
    };

    for (int i = 0; i < coordArr.size; i++)
    {
        if (coordTocheck1.x == coordArr.coords[i].x && coordTocheck1.y == coordArr.coords[i].y ||
        coordToCheck2.x == coordArr.coords[i].x && coordToCheck2.y == coordArr.coords[i].y) 
        {
            return true;
        }
        
    }
    return false;
}