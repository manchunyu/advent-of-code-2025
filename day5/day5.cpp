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

// typedef struct {
//     long* ids;
//     int size;
//     int capacity;
// } IdArray;

// bool isFresh(long id, RangeArray arr);
void mergeSort(Range arr[], int low , int high);
void merge(Range arr[], int l, int m, int r);
int main(void)
{
    char buffer[256]; 
    bool blankLineFound = false;

    RangeArray rangeArr = {
        .ranges = NULL, 
        .size = 0, 
        .capacity = 500000, // TO CHANGE!
    };

    // Part 1
    // IdArray idArr = {
    //     .ids = NULL,
    //     .size = 0,
    //     .capacity = 600 // TO CHANGE!
    // };

    rangeArr.ranges = (Range*) malloc(sizeof(Range) * rangeArr.capacity);
    if (NULL == rangeArr.ranges)
    {
        return 1;
    }

    // newRangeArr.ranges = (Range*) malloc(sizeof(Range) * rangeArr.capacity);
    // if (NULL = newRangeArr.ranges)
    // {
    //     free(rangeArr.ranges);
    //     free(newRangeArr.ranges);
    //     return 1;
    // }

    

    // Part 1

    // idArr.ids = (long*) malloc(sizeof(int) * idArr.capacity);
    // if (NULL == idArr.ids)
    // {
    //     free(rangeArr.ranges);
    //     free(idArr.ids);
    //     return 1;
    // }
    

    while (NULL != fgets(buffer, sizeof(buffer), stdin)) 
    {   
        if (buffer[0] == '\n') 
        {
            blankLineFound = true;
            continue;
        }

        Range range;
        // long id;

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

    //DEBUG
    // for (int i = 0; i < idArr.size; i++)
    // {
    //     printf("IN ID ARR: %i\n", idArr.ids[i]);
    // }


    mergeSort(rangeArr.ranges, 0, rangeArr.size - 1);

    // Debug test sorted
    // for (int i = 0; i < rangeArr.size; i++) 
    // {
    //     printf("IN ARR: %li to %li\n", rangeArr.ranges[i].min, rangeArr.ranges[i].max);
    // }
    Range prevRange = rangeArr.ranges[0];
    long count = 0;
    for (int i = 1; i < rangeArr.size; i++)
    {
        if (rangeArr.ranges[i].min > prevRange.max)
        {
            count += prevRange.max - prevRange.min + (long)1;
            prevRange = rangeArr.ranges[i];
        }
        else
        {
            prevRange.max = (prevRange.max >= rangeArr.ranges[i].max) ? prevRange.max : rangeArr.ranges[i].max;
        }
    }
    count += prevRange.max - prevRange.min + (long)1;
    printf("%li\n", count);





    // Part 1
    // int count = 0;
    // for (int i = 0; i < idArr.size; i++)
    // {
    //     if (isFresh(idArr.ids[i], rangeArr))
    //     {
    //         count++;
    //     }
    // }

    // printf("%i", count);

    free(rangeArr.ranges);
    // free(newRangeArrArr.ids);

    return 0;
}


// Part 1
// bool isFresh(long id, RangeArray arr)
// {

//     for (int i = 0; i < arr.size; i++)
//     {
//         if (id >= arr.ranges[i].min && id <= arr.ranges[i].max)
//         {
//             return true;
//         }
//     }

//     return false;
// }

// GEEKS4GEEKS mergesort
void mergeSort(Range arr[], int low , int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}


// GEEKS4GEEKS merge
void merge(Range arr[], int l, int m, int r)
{
    
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    Range L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].min <= R[j].min) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}