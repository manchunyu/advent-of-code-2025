#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long min;
    long max;
} Range;

typedef struct {
    Range* ranges;
    int size;
    int capacity;
} RangeArray;

typedef struct {
    long* ids;
    int size;
    int capacity;
} IdArray;

bool isFresh(long id, RangeArray arr);

int main(void)
{
    char buffer[256]; 
    bool blankLineFound = false;

    RangeArray rangeArr = {
        .ranges = NULL, 
        .size = 0, 
        .capacity = 50000 // TO CHANGE!
    };

    IdArray idArr = {
        .ids = NULL,
        .size = 0,
        .capacity = 600 // TO CHANGE!
    };

    rangeArr.ranges = (Range*) malloc(sizeof(Range) * rangeArr.capacity);
    if (NULL == rangeArr.ranges)
    {
        free(rangeArr.ranges);
        return 1;
    }

    idArr.ids = (long*) malloc(sizeof(int) * idArr.capacity);
    if (NULL == idArr.ids)
    {
        free(rangeArr.ranges);
        free(idArr.ids);
        return 1;
    }
    

    while (NULL != fgets(buffer, sizeof(buffer), stdin)) 
    {   
        if (strcmp(buffer, "\n") == 0) 
        {
            blankLineFound = true;
            continue;
        }

        Range range;
        long id;

        if (!blankLineFound)
        {
            if (sscanf(buffer, "%ld-%ld", &range.min, &range.max) == 2)
            {
                // printf("%i to %i\n", range.min, range.max); // DEBUG
                rangeArr.ranges[rangeArr.size++] = range;
            }
        }
        else 
        {
            // Part 1
            
            // if (sscanf(buffer, "%ld", &id) == 1)
            // {
            //     // printf("id: %i\n", id); // DEBUG
            //     idArr.ids[idArr.size++] = id;
            // }

            // Part 2
            break;
        }
    }

    // DEBUG
    // for (int i = 0; i < rangeArr.size; i++) 
    // {
    //     printf("IN ARR: %i to %i\n", rangeArr.ranges[i].min, rangeArr.ranges[i].max);
    // }

    // for (int i = 0; i < idArr.size; i++)
    // {
    //     printf("IN ID ARR: %i\n", idArr.ids[i]);
    // }

    int count = 0;


    // Part 1

    // for (int i = 0; i < idArr.size; i++)
    // {
    //     if (isFresh(idArr.ids[i], rangeArr))
    //     {
    //         count++;
    //     }
    // }

    printf("%i", count);

    free(rangeArr.ranges);
    free(idArr.ids);

    return 0;
}

bool isFresh(long id, RangeArray arr)
{

    for (int i = 0; i < arr.size; i++)
    {
        if (id >= arr.ranges[i].min && id <= arr.ranges[i].max)
        {
            return true;
        }
    }

    return false;
}