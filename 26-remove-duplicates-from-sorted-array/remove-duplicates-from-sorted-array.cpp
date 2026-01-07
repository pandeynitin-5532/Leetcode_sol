class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> expectedNums(0,n);
        unordered_set<int> s(nums.begin(), nums.end());
        int k=s.size();
        vector<int> v(s.begin(), s.end());
        nums=v;
        sort(nums.begin(),nums.end());
        return k;
    }
};