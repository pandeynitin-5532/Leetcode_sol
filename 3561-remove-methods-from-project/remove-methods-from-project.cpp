class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n), rg(n);
        for (auto &e : invocations) {
            g[e[0]].push_back(e[1]);
            rg[e[1]].push_back(e[0]);
        }

        vector<int> bad(n), vis(n);

        function<void(int)> dfs = [&](int u) {
            bad[u] = 1;
            for (int v : g[u])
                if (!bad[v])
                    dfs(v);
        };

        dfs(k);

        for (int i = 0; i < n; i++) {
            if (!bad[i]) {
                for (int v : g[i]) {
                    if (bad[v]) {
                        vector<int> ans(n);
                        iota(ans.begin(), ans.end(), 0);
                        return ans;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!bad[i])
                ans.push_back(i);
        return ans;
    }
};