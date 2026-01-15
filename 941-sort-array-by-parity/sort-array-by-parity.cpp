class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        while(l<h){
            if(nums[l]%2 != 0 && nums[h]%2==0){
                int temp=nums[l];
                nums[l]=nums[h];
                nums[h]=temp;
                l++;
                h--;
            }
            else if(nums[l]%2==0){
                l++;
            }
            else {
                h--;
            }
        }
        return nums;
    }
};