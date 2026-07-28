int maxOperations(int* nums, int numsSize, int k) {
    int count = 0;
    int* arr = calloc(sizeof(int), k);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < k) {
            int target = k - nums[i];
            if (arr[target] == 0) {
                arr[nums[i]]++;
            } else {
                count++;
                arr[target]--;
            }
        }
    }
    free(arr);
    return count;
}