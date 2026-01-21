class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> res;
        for (int x : nums) {
            if (s.find(x) != s.end()) {
                res.push_back(x);
            }
            else {
                s.insert(x);
            }
        }
        unordered_set <int> q(nums.begin(),nums.end());
        for(int i = 1; i <= nums.size(); i++){
            if(s.find(i) == q.end())res.push_back(i);
        }
        return res;
    }
};