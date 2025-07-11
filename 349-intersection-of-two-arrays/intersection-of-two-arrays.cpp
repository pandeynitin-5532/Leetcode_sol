class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> m;
        for (auto n : nums1) {
            m[n] = true;
        }
        vector<int> result;
        for (auto n : nums2){
            if (m.find(n) != m.end() && m[n] ){
                result.push_back(n);
                m[n]=false;
            }                    
        }
        return result;
    }
};