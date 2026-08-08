int minSubArrayLen(int target, int* nums, int n) {
    int l=0,r=0,sum=0,len=INT_MAX;
    for(;r<n;r++)
    {   sum+=nums[r];
        while(sum>=target)
        {   len=(len<r-l+1)?len:r-l+1;
            sum-=nums[l++];
        }
    }
    return (len==INT_MAX)?0:len;
    
}