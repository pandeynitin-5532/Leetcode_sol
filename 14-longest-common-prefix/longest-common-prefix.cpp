class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        string p="";
        string k=strs[0];
        for(int i=1;i<strs.size();i++){
            string cm="";
            int n=min(k.length(),strs[i].size());
            for(int j=0;j<n;j++){
                if(k[j]==strs[i][j]){
                    cm+=k[j];
                }
                else break;
            }
            k=cm;
            if(k.empty()) return"";
        }
        return k;
    }
};