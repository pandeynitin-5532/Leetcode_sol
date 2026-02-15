class Solution {
public:
    bool isPerfectSquare(int num) {
       int l=0;
       int h=num;
       while(l<=h){
        long long mid=(l+h)/2;
        if(mid*mid==num){
            return true;}
        else if(mid*mid<num){
            l=mid+1;
        }
        else {
            h=mid-1;
        }
       }
       return false;

    }
};