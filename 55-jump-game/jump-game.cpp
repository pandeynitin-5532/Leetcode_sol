class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);
        dp[0] = 1;

        for(int i = 0; i < n; i++) {
            if(dp[i] == 1) {
                for(int jump = 1; jump <= nums[i] && i + jump < n; jump++) {
                    dp[i + jump] = 1;
                }
            }
        }

        return dp[n - 1];
    }
};