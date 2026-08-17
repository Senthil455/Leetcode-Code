#include <stdlib.h>
#include <stdio.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if(numsSize == 0){
        *returnSize = 0;
        return NULL;
    }

    char **out = (char **)malloc(numsSize * sizeof(char*));
    int k = 0;

    int start = nums[0];

    for(int i = 0; i < numsSize; i++){
        // check end of range
        if(i == numsSize - 1 || nums[i] + 1 != nums[i+1]){
            int end = nums[i];

            // allocate enough space
            out[k] = (char*)malloc(25 * sizeof(char));

            if(start == end){
                sprintf(out[k], "%d", start);
            } else {
                sprintf(out[k], "%d->%d", start, end);
            }

            k++;
            if(i != numsSize - 1)
                start = nums[i+1];
        }
    }

    *returnSize = k;
    return out;
}