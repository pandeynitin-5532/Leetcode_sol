class Solution {
public:
    void generatesubsets(int index , vector<int>& nums, vector<int>& current, vector<vector<int>>& masterList){
        if(index==nums.size()){
            masterList.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        generatesubsets(index + 1, nums, current, masterList);
        
        current.pop_back();
        generatesubsets(index + 1, nums, current, masterList);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> masterList;
        vector<int> current;
        generatesubsets(0, nums, current, masterList);
        return masterList;
    }
};
