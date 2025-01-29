// classic DSU
class Solution {
private:
    const static int maxn = 1002;
    int par[maxn];
    int sz[maxn];

    int root(int u) {
        while (par[u] != u) u = par[u];
        return u;
    }

    bool join(int u, int v) {
        int up = root(u), vp = root(v);
        if (up == vp) return false;
        if (sz[vp] > sz[up]) swap(up, vp);
        par[vp] = up;
        sz[up] += sz[vp];
        sz[vp] = 0;
        return true;
    }

    void init() {
        for (int i = 0; i < maxn; i++) {
            par[i] = i; sz[i] = 1;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        vector<int> ans;
        for (vector<int> &e : edges) {
            if (!join(e[0], e[1])) ans = e;
        }
        return ans;
    }
};

// DFS Cycle Detection
class Solution {
private:
    const static int maxn = 1002;
    vector<int> graph[maxn];
    bool isInCycle[maxn];
    int vis[maxn];

    void dfs(int cur, int par) {
        if (vis[cur] != 0) { // cycle detected
            int st = cur;
            vis[st] = par;
            do {
                isInCycle[cur] = 1;
                cur = vis[cur];
            } while (cur != st);
            return;
        }
        vis[cur] = par;
        for (int v : graph[cur]) {
            if (v != par) dfs(v, cur);
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (vector<int> &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(1, -1);
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (isInCycle[edges[i][0]] && isInCycle[edges[i][1]]) return edges[i];
        }
        return {};
    }
};
