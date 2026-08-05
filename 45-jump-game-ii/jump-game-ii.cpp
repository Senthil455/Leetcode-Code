class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currEnd = 0;   // current jump range end
        int maxReach = 0;  // farthest index seen in current range

        // Scan range by range (like BFS levels).
        for (int i = 0; i < n - 1; ++i) {
            // While we are inside current range, keep extending farthest reach.
            maxReach = max(maxReach, i + nums[i]);

            // Only jump when we finish current range.
            if (i == currEnd) {
                ++jumps;
                currEnd = maxReach;

                // Early stop once we can reach the last index.
                if (currEnd >= n - 1) break;
            }
        }

        return jumps;
    }
};