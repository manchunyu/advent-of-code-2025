#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* numbers;
    char* operations;
    int numbersLength;
    int operationsLength;
    int capacity;
} IntArray;


int main(void)
{
    char buffer[1000000];
    IntArray intArr = {
        .numbers = NULL,
        .operations = NULL,
        .numbersLength = 0,
        .operationsLength = 0,
        .capacity = 200000,
    };

    intArr.numbers = malloc(sizeof(int) * intArr.capacity);
    if (NULL == intArr.numbers) 
    {
        return 1;
    }
    intArr.operations = malloc(sizeof(char) * intArr.capacity);
    if (NULL == intArr.operations)
    {
        free(intArr.numbers);
        return 1;
    }



    while (fgets(buffer, sizeof(buffer), stdin))
    {
        char* token = strtok(buffer, " \t\r\n");
        while (token) 
        {
            char* end;
            long value = strtol(token, &end, 10);

            if (end != token) 
            { 
                intArr.numbers[intArr.numbersLength++] = value;
            } 
            else 
            {

                intArr.operations[intArr.operationsLength++] = *token;
            }

            token = strtok(NULL, " \t\r\n");
        }
    }

    long total = 0;
    for (int i = 0; i < intArr.operationsLength; i++)
    {
        if (intArr.operations[i] == '*') 
        {
            long subtotal = 1;
            for (int j = i; j < intArr.numbersLength; j += intArr.operationsLength) 
            {
                subtotal *= intArr.numbers[j];
            }
            total += subtotal;
        }
        else if (intArr.operations[i] == '+') 
        {
            long subtotal = 0;
            for (int j = i; j < intArr.numbersLength; j += intArr.operationsLength) 
            {
                subtotal += intArr.numbers[j];
            }
            total += subtotal;
        }
    }
        
    printf("%ld\n", total);


    printf("nums len: %i, ops len: %i", intArr.numbersLength, intArr.operationsLength);

    free(intArr.numbers);
    free(intArr.operations);
    return 0;
}