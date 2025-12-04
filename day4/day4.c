#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    bool removed;
} Coordinate;

typedef struct {
    Coordinate* coordinates;
    int size;
    int capacity;
} CoordArray;

bool isPaperRoll(Coordinate target, CoordArray paperRollCoords);

int main(void)
{
    char grid[256][256];
    CoordArray paperRollCoords = {
        .coordinates = NULL,
        .size = 0,
        .capacity = 12000, // TO CHANGE
    };

    paperRollCoords.coordinates = malloc(sizeof(Coordinate) * paperRollCoords.capacity);
    if (paperRollCoords.coordinates == NULL) {
        return 1;
    }

    int gridHeight = 0;
    int gridWidth = 0;

    while (NULL != fgets(grid[gridHeight], 256, stdin))
    {
        printf("%s\n", grid[gridHeight]);
        gridWidth = strlen(grid[gridHeight]);

        for (int i = 0; i < gridWidth; i++)
        {
            if (grid[gridHeight][i] == '@')
            {
                Coordinate foundPaperRollCoord = {.x = i, .y = gridHeight, .removed = false};
                paperRollCoords.coordinates[paperRollCoords.size++] = foundPaperRollCoord;
            }
        }

        gridHeight++;
    }

    // DEBUG
    // printf("%i", paperRollCoords.size);

    // for (int i = 0; i < paperRollCoords.size; i++)
    // {
    //     printf("x = %i, y = %i", paperRollCoords.coordinates[i].x, paperRollCoords.coordinates[i].y);
    // }

    Coordinate coordsToCheck[] = {
        {-1, -1}, {0, -1},  {1, -1},
        {-1, 0},            {1, 0},
        {-1, 1},  {0, 1},   {1, 1}
    };
    int NO_OF_COORDINATE_TO_CHECK = sizeof(coordsToCheck) / sizeof(Coordinate);

    int p1_total = 0;
    int p2_total = 0;
    
 
    for (int i = 0; i < paperRollCoords.size; i++) 
    {
        int noOfRollsAround = 0;
        for (int k = 0; k < NO_OF_COORDINATE_TO_CHECK; k++)
        {
            Coordinate target = {
                    .x = paperRollCoords.coordinates[i].x + coordsToCheck[k].x,
                    .y = paperRollCoords.coordinates[i].y + coordsToCheck[k].y
            };
            if (target.x < 0 || target.y < 0 || target.x >= gridWidth || target.y >= gridHeight)
            {
                continue;
            } 
            if (isPaperRoll(target, paperRollCoords))
            {
                noOfRollsAround++;
            }
        }
        if (noOfRollsAround < 4)
        {
            p1_total++;
        }
    }


    printf("%i", p1_total);
    free(paperRollCoords.coordinates);
    return 0;
}


bool isPaperRoll(Coordinate target, CoordArray paperRollCoords)
{

    for (int i = 0; i < paperRollCoords.size; i++)
    {
        if (paperRollCoords.coordinates[i].x == target.x && paperRollCoords.coordinates[i].y == target.y)
        {
            return true;
        }
    }

    return false;
}