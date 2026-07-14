class Solution {
public:
    static const int MOD = 1000000007;
    int dp[201][201][201];

    int solve(int i, int g1, int g2, vector<int>& nums) {
        if (i == nums.size()) return g1 && g2 && g1 == g2;
        int &res = dp[i][g1][g2];
        if (res != -1) return res;

        long long ans = solve(i + 1, g1, g2, nums);
        ans += solve(i + 1, g1 ? gcd(g1, nums[i]) : nums[i], g2, nums);
        ans += solve(i + 1, g1, g2 ? gcd(g2, nums[i]) : nums[i], nums);

        return res = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};