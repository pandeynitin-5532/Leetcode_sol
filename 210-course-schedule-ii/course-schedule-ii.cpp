class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses), ans;
        for (auto &p : prerequisites) {
            g[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : g[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};