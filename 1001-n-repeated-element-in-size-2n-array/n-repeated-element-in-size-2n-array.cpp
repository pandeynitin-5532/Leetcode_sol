class Solution {
public:
    int hash_table[10000] = { 0 };
    int p=0;
    int repeatedNTimes(vector<int>& A) {
        for(int i=0;i<A.size();i++){
            hash_table[A[i]]++;
            if(hash_table[A[i]] == A.size()/2 )
                p=A[i];
        }
        return p;
    }
};