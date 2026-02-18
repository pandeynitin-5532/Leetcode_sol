class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> ans;
        while(n!=0){
            int r=n%2;
            n=n/2;
            ans.push_back(r);
        }
        int i=0,cnt=0;
        while(i<ans.size()-1){
            if(ans[i]==ans[i+1]){
                cnt++;
            }
            i++;
        }
        if(cnt>=1){
            return false;
        }
        return true;
    }
};