int pivotIndex(int* nums, int numsSize) {
    for(int i=0; i<numsSize; i++){
        int left =0;
        int right =0;
        for(int j=i-1; j>=0; j--){
            left += nums[j];
        }
        for(int j=i+1; j<numsSize; j++){
            right += nums[j];
        }
        if(left == right){
            return i;
        }
    }
    return -1;
}