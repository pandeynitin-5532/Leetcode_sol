class Solution {
public:
    void generatePermutations(vector<int>& nums, vector<int>& current, vector<bool>& visited, vector<vector<int>>& masterList) {
        if (current.size() == nums.size()) {
            masterList.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }

            current.push_back(nums[i]);
            visited[i] = true;

            generatePermutations(nums, current, visited, masterList);

            visited[i] = false;
            current.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> masterList;
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        generatePermutations(nums, current, visited, masterList);
        return masterList;
    }
};
