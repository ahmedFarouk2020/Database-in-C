#include "sort.h"




uint8_t Is_sorted (database_t* arr)
{
    // iterate over the whole array
    for (int j = 0; j < size-1; j++)
    {
        // left element  >  right element (not sorted)
        if(arr[j].PAN > arr[j+1].PAN) {
            // printf("Not sorted\n");
            return 0;  // not sorted
        }
    }
    // printf("sorted\n");
    return 1;    // sorted
}



void bubbleSort(database_t* arr)
{
    uint8_t dynamicSize = size; // decremented after each iteration on the array
    /* Bubble sort */
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < dynamicSize-1; j++)
        {
            
            if(arr[j].PAN > arr[j+1].PAN) {
                // SWAP
                database_t temp = {arr[j].PAN, arr[j].balance};
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        dynamicSize--;
    }
}