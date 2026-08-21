class Solution {
public:
    long long cntLessThanEqualToX(vector<int>& coins, long long x)
    {
        int mid = coins.size();
        int allOnes = (1 << mid) - 1;
        long long cnt = 0;
        
        for(int mask = 1; mask <= allOnes; mask++)
        {
            long long setBitsLCM = 1;
            
            for(int j = 0; j < mid; j++)
            {
                if(mask & (1 << j))
                    setBitsLCM = lcm(setBitsLCM, coins[j]);
            }
            
            if(__builtin_popcount(mask) & 1)
                cnt += x / setBitsLCM;
            else
                cnt -= x / setBitsLCM;
        }
        
        return cnt;
    }
    
    long long findKthSmallest(vector<int>& coins, int k) {
        
        long long l = 1, h = 25 * 2 * 1e9 + 25;
        long long ans = 0;
        
        while(l <= h)
        {
            long long mid = (l + h) / 2;
            
            long long cnt = cntLessThanEqualToX(coins, mid);
            
            if(cnt < k)
                l = mid + 1;
            else
            {
                ans = mid;
                h = mid - 1;
            }
        }
        
        return ans;
    }
};