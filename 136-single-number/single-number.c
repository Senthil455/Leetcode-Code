int singleNumber(int* nums, int numsSize) {
    int max = nums[0], min = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max) max = nums[i];
        if (nums[i] < min) min = nums[i];
    }
    int range = max - min + 1;
    int *count = calloc(range, sizeof(int));
    for (int i = 0; i < numsSize; i++)
        count[nums[i] - min]++;
    for (int i = 0; i < numsSize; i++)
        if (count[nums[i] - min] == 1)
            return nums[i];
    return -1;
}
