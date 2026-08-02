int findDuplicate(int* nums, int numsSize) {
    int max=nums[0];
    for(int i=0; i<numsSize; i++)
        if(max<nums[i]) max=nums[i];
    int *count=(int *)calloc(max+1, sizeof(int));
    for(int i=0; i<numsSize; i++){
        count[nums[i]]++;
    }
    for(int i=0; i<=max; i++){
        if(count[i]>=2) return i;
    }
    free(count);
    return -1;
}