class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_set<int>s;
        for (int x : nums) {
            if (s.find(x) != s.end()) {
                res.push_back(x);
            }
            else {
                s.insert(x);
            }
        }
        return res;
    }
};