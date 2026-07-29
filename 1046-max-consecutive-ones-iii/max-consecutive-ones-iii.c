int longestOnes(int* nums, int numsSize, int k) {
    int zero_cnt = 0, l = 0, ans = 0;
    for (int r = 0; r < numsSize; ++r) {
        if (nums[r] == 0)
            zero_cnt++;
        while (zero_cnt > k)
            if (nums[l++] == 0)
                zero_cnt--;
        ans = fmax(ans, r - l + 1);
    }
    return ans;
}