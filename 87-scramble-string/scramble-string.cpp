class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        unordered_map<string, bool> memo;
        function<bool(int,int,int)> dfs = [&](int i, int j, int len) {
            string key = to_string(i) + "," + to_string(j) + "," + to_string(len);
            if (memo.count(key)) return memo[key];
            if (s1.substr(i, len) == s2.substr(j, len))
                return memo[key] = true;
            vector<int> cnt(26);
            for (int k = 0; k < len; k++) {
                cnt[s1[i + k] - 'a']++;
                cnt[s2[j + k] - 'a']--;
            }
            for (int x : cnt)
                if (x) return memo[key] = false;
            for (int k = 1; k < len; k++) {
                if ((dfs(i, j, k) && dfs(i + k, j + k, len - k)) ||
                    (dfs(i, j + len - k, k) && dfs(i + k, j, len -k)))
                    return memo[key] = true;
            }
            return memo[key] = false;
        };
        return dfs(0,0 , n);
    }
};