class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        vector <int> ans;
        for(int i=0;i<nums.size();i++){
            int count=0;
            for(int j=0;j<ans.size();j++){
                if(nums[i]==ans[j]){
                    count++;
                }
            }
            if (count==0){
                ans.push_back(nums[i]);
            }
        }
        sort(ans.begin(),ans.end());
        int p=ans.size();
        if(p>=3){
            return ans[p-3];
        }
        else {
            return ans[p-1];
        }
        
    }
};