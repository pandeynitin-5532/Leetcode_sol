class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,k;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                k=i;
                l++;
            }
        }
        if(l>=1){
            return k;
        }
        else return -1;
     
    }
};