class Solution {
public:
    static constexpr long long LIM = 1000000LL + 1;

    long long combCap(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        __int128 res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > LIM) return LIM;
        }
        return (long long)min(res, (__int128)LIM);
    }

    long long countWays(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;
        long long ans = 1;
        for (int x : cnt) {
            if (!x) continue;
            ans = min(LIM, ans * combCap(rem, x));
            rem -= x;
            if (ans >= LIM) return LIM;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26);
        string mid;
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1) mid.push_back(char('a' + i));
        }

        if (countWays(half) < k) return "";

        string left;
        int len = 0;
        for (int x : half) len += x;

        for (int pos= 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (!half[c]) continue;
                half[c]--;
                long long ways = countWays(half);
                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }
                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};