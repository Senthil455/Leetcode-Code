double findMaxAverage(int* nums, int numsSize, int k) {
    double max = 0;
    int i = 0;
    double sum = 0;
    while (i < k) {
        sum += nums[i];
        i++;
    }
    max = sum / k;
    while (i < numsSize) {
        sum += nums[i] - nums[i - k];
        if (sum / k > max) {
            max = sum / k;
        }
        i++;
    }
    return max;
}