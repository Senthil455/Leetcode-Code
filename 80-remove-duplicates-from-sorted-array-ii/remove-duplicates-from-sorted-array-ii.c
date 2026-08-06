int removeDuplicates(int* nums, int numsSize) {
    // If array has 2 or fewer elements, all elements are valid
    if (numsSize <= 2) {
        return numsSize;
    }

    int k = 2; // Pointer to place the next valid element

    for (int i = 2; i < numsSize; i++) {
        // Compare current element with the element two positions back in the valid region
        if (nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}