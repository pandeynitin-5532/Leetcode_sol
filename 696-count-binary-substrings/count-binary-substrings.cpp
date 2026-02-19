class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> ans;
        int cnt=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                ans.push_back(cnt);
                cnt=1;
            }
        }
        ans.push_back(cnt);
        vector<int> runs;
        for(int i=0;i<ans.size()-1;i++){
            runs.push_back(min(ans[i],ans[i+1]));
        }
        int sum=0;
        for(int i=0;i<runs.size();i++){
            sum+=runs[i];
        }
        return sum;
    }
};