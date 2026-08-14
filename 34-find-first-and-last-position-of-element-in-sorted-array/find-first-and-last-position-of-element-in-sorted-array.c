/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findFirstPosition(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result = mid;
            right = mid - 1; // Continue searching in the left half
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int findLastPosition(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result = mid;
            left = mid + 1; // Continue searching in the right half
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) {
        return NULL; // Handle malloc failure
    }

    result[0] = findFirstPosition(nums, numsSize, target);
    result[1] = findLastPosition(nums, numsSize, target);

    return result;
}