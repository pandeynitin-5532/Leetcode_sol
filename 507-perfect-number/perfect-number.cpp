class Solution {
public:
    bool checkPerfectNumber(int num) {
        int n=1;
        int sum=0;
        while(n<num){
            if(num%n==0){
                sum+=n;
            }
            n++;
        }
        if(sum==num) return true;
        return false;
    }
};