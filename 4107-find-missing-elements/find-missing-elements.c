/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int min=nums[0],max=nums[0], k=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]<min) min=nums[i];
        else if(nums[i]>max) max=nums[i];
    }
    int *out=(int *)malloc((max-min+1)*sizeof(int));
    for(int i=min;i<=max;i++){
        int found=0;
        for(int j=0; j<numsSize; j++){
            if(i==nums[j]){
                found=1;
                break;
            }
        }
        if(found==0)
            out[k++]=i;
    }
    *returnSize=k;
    return out;
}