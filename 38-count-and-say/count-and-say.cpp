class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string t = "";

            for (int j = 0; j < s.size(); ) {
                int cnt = 0;
                char c = s[j];

                while (j < s.size() && s[j] == c) {
                    cnt++;
                    j++;
                }

                t += to_string(cnt);
                t += c;
            }

            s = t;
        }

        return s;
    }
};