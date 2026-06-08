class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans.push_back(nums[i]);
            }
        }
        vector<int> ans1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                ans1.push_back(nums[i]);
            }
        }
        vector<int> res;
        int p=0;
        int n=0;
        while(p < ans.size() && n < ans1.size()){
            res.push_back(ans[p]);
            p++;
            res.push_back(ans1[n]);
            n++;
        }
        return res;
    }
};