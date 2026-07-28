void moveZeroes(int* nums, int numsSize) {
    int z =0;
    int k=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i] != 0){
            nums[k++] = nums[i];
        }
    }
    if(k!=numsSize){
        for(int i=k; i<numsSize; i++){
            nums[i] = 0;
        }
    }
}