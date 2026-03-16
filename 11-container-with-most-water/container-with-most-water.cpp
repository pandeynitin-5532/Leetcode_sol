class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int m=0;
        int a=n-1;
        int max=0;
        while(m<a){
            if(height[m]>height[a]){
                int ar=height[a]*(a-m);
                if(max<ar){
                    max=ar;
                }
                a--;
            }
            else if(height[m]<=height[a]){
                int ar=height[m]*(a-m);
                if(max<ar){
                    max=ar;
                }
                m++;
            }
        }
        return max;
    }
};