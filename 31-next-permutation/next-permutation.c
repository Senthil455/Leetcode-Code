void nextPermutation(int* nums, int numsSize) {
  /* Find the first place moving from right to left that is not assending */
  int dest = numsSize - 1;
  while (dest-- && nums[dest] >= nums[dest + 1])
    ;

  if (0 <= dest) /* Found a destination to change */ {
    /* Find the right most value greater than our destination (there must be one) */
    int target = numsSize;
    while (nums[--target] <= nums[dest])
      ;

    /* Swap the destination with the target */
    int tmp = nums[dest];
    nums[dest] = nums[target];
    nums[target] = tmp;
  }
  
  /* Reverse everything right of our destination */
  for (int back = numsSize - 1; dest + 1 < back; ) {
    int tmp = nums[++dest];
    nums[dest] = nums[back];
    nums[back--] = tmp;
  }
}