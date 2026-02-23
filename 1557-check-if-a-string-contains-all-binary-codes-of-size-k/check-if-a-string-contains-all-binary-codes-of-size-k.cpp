class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int total = 1 << k;
        if (n - k + 1 < total) return false;

        vector<bool> seen(total, false);
        int mask = 0;

        for (int i = 0; i < k - 1; i++) {
            mask = (mask << 1) | (s[i] - '0');
        }

        int cnt = 0;
        for (int i = k - 1; i < n; i++) {
            mask = ((mask << 1) & (total - 1)) | (s[i] - '0');
            if (!seen[mask]) {
                seen[mask] = true;
                cnt++;
                if (cnt == total) return true;
            }
        }
        return false;
    }
};