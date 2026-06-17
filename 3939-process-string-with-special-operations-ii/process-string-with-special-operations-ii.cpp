class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);

        long long cur = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                cur = max(0LL, cur - 1);
            } else if (s[i] == '#') {
                cur *= 2;
            } else if (s[i] == '%') {
            } else {
                cur++;
            }
            len[i] = cur;
        }

        if (k >= cur) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long m = len[i];

            if (c >= 'a' && c <= 'z') {
                if (k == m - 1) return c;
            } else if (c == '*') {
                continue;
            } else if (c == '#') {
                m /= 2;
                if (k >= m) k -= m;
            } else {
                k = m - 1 - k;
            }

            if (i > 0) cur = len[i + 1];
            else cur = 0;
        }

        return '.';
    }
};