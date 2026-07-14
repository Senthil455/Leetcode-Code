class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int solve(vector<int>& nums, int i, int gcd1, int gcd2,
              vector<vector<vector<int>>>& memo) {
        int n = nums.size();

        if (i == n) {
            if (gcd1 == 0 || gcd2 == 0) return 0;
            return gcd1 == gcd2 ? 1 : 0;
        }

        if (memo[i][gcd1][gcd2] != -1) return memo[i][gcd1][gcd2];

        long long skip = solve(nums, i + 1, gcd1, gcd2, memo);
        long long takeIn1 = solve(nums, i + 1, __gcd(gcd1, nums[i]), gcd2, memo);
        long long takeIn2 = solve(nums, i + 1, gcd1, __gcd(gcd2, nums[i]), memo);

        memo[i][gcd1][gcd2] = (skip + takeIn1 + takeIn2) % MOD;
        return memo[i][gcd1][gcd2];
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> memo(
            n, vector<vector<int>>(201, vector<int>(201, -1)));

        return solve(nums, 0, 0, 0, memo);
    }
};