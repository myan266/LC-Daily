// Modified Floyd-Warshall
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        // A is a prereq of B <-> there exists a path in the DAG from A to B
        vector<vector<bool>> floyd(n, vector<bool>(n, 0));

        for (vector<int> &pre : prereq) {
            floyd[pre[0]][pre[1]] = 1;
        }
        for (int i = 0; i < n; i++) floyd[i][i] = 1;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!floyd[i][k] || !floyd[k][j] || floyd[i][j]) continue;
                    floyd[i][j] = true;
                }
            }
        }

        int m = queries.size();
        vector<bool> ans(m);

        for (int i = 0; i < m; i++) {
            ans[i] = floyd[queries[i][0]][queries[i][1]];
        }

        return ans;

    }
};

// Topological sort solution with bitmask
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        // A is a prereq of B <-> there exists a path in the DAG from A to B
        vector<bitset<100>> preq(n);
        vector<vector<int>> graph(n);
        vector<int> inDeg(n);

        for (vector<int> &pre : prereq) {
            preq[pre[1]].set(pre[0], 1);
            graph[pre[0]].push_back(pre[1]);
            inDeg[pre[1]]++;
        }

        queue<int> topo;

        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) topo.push(i);
        }
        
        while (!topo.empty()) {
            int cur = topo.front(); topo.pop();
            for (int v : graph[cur]) {
                preq[v] |= preq[cur];
                inDeg[v]--; 
                if (inDeg[v] == 0) topo.push(v);
            }
        }

        int m = queries.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) ans[i] = preq[queries[i][1]][queries[i][0]];

        return ans;
    }
};
