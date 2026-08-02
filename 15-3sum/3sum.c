#include <stdlib.h> // For qsort, malloc, realloc, free

// Comparison function for qsort
int compareIntegers(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // 1. Sort the array
    qsort(nums, numsSize, sizeof(int), compareIntegers);

    *returnSize = 0;
    int capacity = 16; // Initial capacity for the result arrays

    // Allocate initial memory for the result array (array of pointers)
    int** res = (int**)malloc(capacity * sizeof(int*));
    // Allocate initial memory for the column sizes array
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }

        int j = i + 1; // Left pointer
        int k = numsSize - 1; // Right pointer

        while (j < k) {
            int total = nums[i] + nums[j] + nums[k];

            if (total > 0) {
                k--;
            } else if (total < 0) {
                j++;
            } else {
                // Found a triplet, check if we need to resize
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    res = (int**)realloc(res, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                
                // Allocate memory for the new triplet
                res[*returnSize] = (int*)malloc(3 * sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[j];
                res[*returnSize][2] = nums[k];
                
                // Set the column size for this triplet (always 3)
                (*returnColumnSizes)[*returnSize] = 3;
                
                (*returnSize)++;
                j++;

                // Skip duplicate values for the second element
                while (j < k && nums[j] == nums[j-1]) {
                    j++;
                }
            }
        }
    }
    
    // Note: It's good practice to realloc to the exact size, but not strictly required by LeetCode
    // if (capacity > *returnSize && *returnSize > 0) {
    //     res = (int**)realloc(res, *returnSize * sizeof(int*));
    //     *returnColumnSizes = (int*)realloc(*returnColumnSizes, *returnSize * sizeof(int));
    // } else if (*returnSize == 0) {
    //     free(res);
    //     free(*returnColumnSizes);
    //     return NULL;
    // }

    return res;
}