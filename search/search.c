#include "search.h"



uint8_t binarySearch(database_t* arr, int value) 
{
    uint8_t start = 0;                // start position
    uint8_t end = size-1;          // end position
    uint8_t mid = (start + end) / 2;  // middle position
    uint8_t previousMid = 0;      // the previous value of mid to avoid infinite loop
    uint8_t state = 1;
    while (1)
    {
        // infinite loop?
        if (previousMid == mid)
        {
            // value is not found
            return -1;
        }
        
        // value is found?
        if (arr[mid].PAN == value)
        {
            return mid; // reurn index
        }

        // stuck and didn't find the value?
        if (start == end)
        {
            return -1;  // not found
        }
        
        // the value is at the right side?
        if (arr[mid].PAN < value)
        {
            // update positions
            start = mid+1;
            previousMid = mid;
            mid = (start + end) / 2;
            continue;
        }

        // the value is at the left side?
        if (arr[mid].PAN > value)
        {
            // update positions
            end = mid-1;
            previousMid = mid;
            mid = (start + end) / 2;
            continue;
        } 
    }
   
}
