class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> suspicious;

    void dfs(int node) {
        suspicious[node] = true;

        for (int next : graph[node]) {
            if (!suspicious[next])
                dfs(next);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        graph.resize(n);
        suspicious.assign(n, false);

      
        for (auto &e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

       
        dfs(k);

        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};