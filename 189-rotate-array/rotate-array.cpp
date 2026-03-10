class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> c;
        c.insert(c.end(), nums.end()-k, nums.end());
        c.insert(c.end(), nums.begin(), nums.end()-k);
        nums=c;
    }
};