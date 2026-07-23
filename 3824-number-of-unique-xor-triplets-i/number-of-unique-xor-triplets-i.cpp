class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        int b = 31 - __builtin_clz(n);
        return 1 << (b + 1);
    }
};