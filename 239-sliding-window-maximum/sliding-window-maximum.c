/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int* ans = malloc((numsSize - k + 1) * sizeof(int));
    int* deq = malloc(numsSize * sizeof(int));
    int dbegin = 0, dend = 0;
    int aidx = 0;

    for (int cidx = 0; cidx < numsSize; cidx++) {

        // if current value is larger than the values already in deq --> negate all other values after the current deq value, by decrementing dend pointer. 
        while (dend > dbegin && nums[deq[dend - 1]] <= nums[cidx]) {
            dend--;
        }

        // increment dend, since we are always adding a value in our deq. 
        deq[dend++] = cidx;

        // if the indexes that we store in the deq are too far away -- i.e. outside our sliding window -- we must remove them, just increment dbegin. 
        if (deq[dbegin] <= cidx - k) {
            dbegin++;
        }

        // finally we just save the first element in our deque as the maximum in our answer -- since we manage our deq to be descending order. 
        if (cidx >= k - 1) {
            ans[aidx++] = nums[deq[dbegin]];
        }
    }

    *returnSize = aidx;
    free(deq); 
    return ans;
}