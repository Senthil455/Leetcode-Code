class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>& dp){
        if(i==nums.size())return 0;
        if(dp[i]!=-1)return dp[i];

        //take it
        int upIdx=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
        int nxtIdx=upper_bound(nums.begin(),nums.end(),nums[i]+1)-nums.begin();

        int take=nums[i]*(upIdx-i)+solve(nums,nxtIdx,dp);
        int leave=solve(nums,upIdx,dp);
        return dp[i]=max(take,leave);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);

        
    }
};