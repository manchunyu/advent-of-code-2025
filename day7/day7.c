#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    Coord* coords;
    int size;
    int capacity;
} CoordArr;

int main(void) 
{
    CoordArr coordArr = {
        .coords = NULL,
        .size = 0,
        .capacity = 20000,
    };

    coordArr.coords = malloc(sizeof(Coord) * coordArr.capacity);
    if (NULL == coordArr.coords)
    {
        return 1;
    }


    char rowBuffer[256];
    fgets(rowBuffer, sizeof(rowBuffer), stdin);
    int rowWidth = strlen(rowBuffer);
    for (int i = 0; i < rowWidth; i++)
    {
        if ('S' == rowBuffer[i])
        {
            Coord startingPos = {
                .x = i,
                .y = 1,
            };
            coordArr.coords[0] = startingPos;
        }
    }

    printf("starting pos: x: %i, y: %i\n", coordArr.coords[0].x, coordArr.coords[0].y); // Starting pos debug
    int rowCounter = 1;
    while (NULL != fgets(rowBuffer, sizeof(rowBuffer), stdin))
    {
        if (rowCounter % 2 != 0)
        {
            rowCounter++;
            continue;
        }

        
    }

    free(coordArr.coords);
    return 0;
}