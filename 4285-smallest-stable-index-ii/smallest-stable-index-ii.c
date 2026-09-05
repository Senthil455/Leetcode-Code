#include <stdlib.h>

int firstStableIndex(int* nums, int numsSize, int k) {
    int *prefixMax = (int*)malloc(numsSize * sizeof(int));
    int *suffixMin = (int*)malloc(numsSize * sizeof(int));

    // prefix max
    prefixMax[0] = nums[0];
    for(int i = 1; i < numsSize; i++){
        prefixMax[i] = (nums[i] > prefixMax[i-1]) ? nums[i] : prefixMax[i-1];
    }

    // suffix min
    suffixMin[numsSize-1] = nums[numsSize-1];
    for(int i = numsSize - 2; i >= 0; i--){
        suffixMin[i] = (nums[i] < suffixMin[i+1]) ? nums[i] : suffixMin[i+1];
    }

    // find index
    for(int i = 0; i < numsSize; i++){
        if(prefixMax[i] - suffixMin[i] <= k){
            free(prefixMax);
            free(suffixMin);
            return i;
        }
    }

    free(prefixMax);
    free(suffixMin);
    return -1;
}