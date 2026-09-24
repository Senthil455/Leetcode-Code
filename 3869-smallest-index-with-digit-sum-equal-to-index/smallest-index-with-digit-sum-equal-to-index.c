int smallestIndex(int* nums, int numsSize) {
    int out=-1;
    bool found=false;
    for(int i=0; i<numsSize; i++){
        int sum=0, temp=nums[i];
        while(temp!=0){
            sum+=temp%10;
            temp/=10;
        }
        if(sum==i){
            found=true;
            out=i;
            break;
        }
    }
    return out;
}