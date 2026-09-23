int minOperations(int* nums, int numsSize, int x) {
    int total = 0;

    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }

    int target = total - x;

    if (target < 0) {
        return -1;
    }

    int left = 0;
    int currentSum = 0;
    int maxLen = -1;

    for (int right = 0; right < numsSize; right++) {
        currentSum += nums[right];

        while (currentSum > target && left <= right) {
            currentSum -= nums[left];
            left++;
        }

        if (currentSum == target) {
            int len = right - left + 1;

            if (len > maxLen) {
                maxLen = len;
            }
        }
    }

    if (maxLen == -1) {
        return -1;
    }

    return numsSize - maxLen;
}