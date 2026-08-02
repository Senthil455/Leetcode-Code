int maxSubArray(int* nums, int numsSize) {
    int currSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (currSum + nums[i] > nums[i])
            currSum = currSum + nums[i];
        else
            currSum = nums[i];  
        if (currSum > maxSum)
            maxSum = currSum;
    }
    return maxSum;
}