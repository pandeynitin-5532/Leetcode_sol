class Solution {
public:
    int maxr(vector<int> & nums,int l,int m,int r){
        int ls=INT_MIN;
        int sum=0;
        for(int i=m;i>=l;i--){
            sum+=nums[i];
            ls=max(ls,sum);
        }
        int rs=INT_MIN;
        int sum1=0;
        for(int i=m+1;i<=r;i++){
            sum1+=nums[i];
            rs=max(rs,sum1);
        }
        return ls+rs;
    }
    int maxe(vector<int>& nums,int l,int r){
        if(l==r) return nums[l];
        int m=l+(r-l)/2;
        return max({
            maxe(nums,l,m),
            maxe(nums,m+1,r),
            maxr(nums,l,m,r)
        });
    }
    int maxSubArray(vector<int>& nums) {
        int x=maxe(nums,0,nums.size()-1);
        return x;
    }
};