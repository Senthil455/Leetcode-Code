int singleNumber(int* nums, int numsSize) {
    int i , ones = 0 , twos = 0;
    for(i = 0 ; i < numsSize; i++){
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}