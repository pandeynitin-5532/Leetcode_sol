class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int temp;
        if(n<2) return 0;
        for(int i=1;i<n;++i){
             temp= max(temp,nums[i]-nums[i-1]);
            
        }
        return temp;

        }
        
    
};