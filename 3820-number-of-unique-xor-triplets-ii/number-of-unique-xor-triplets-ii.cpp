class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> pairXor;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                pairXor.insert(nums[i] ^ nums[j]);

        unordered_set<int> result;
        for (int p : pairXor)
            for (int k = 0; k < n; k++)
                result.insert(p ^ nums[k]);

        return result.size();
    }
};