bool increasingTriplet(int* nums, int numsSize) {
    int min = INT_MAX;
    int mid = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        //This stores the first minimum number
        if (nums[i] <= min) {
            min = nums[i];
        //This stores the middle number
        } else if (nums[i] <= mid) {
            mid = nums[i];
        } else {
            // Found a value greater than both min and mid
            return true;
        }
    }

    return false;
}