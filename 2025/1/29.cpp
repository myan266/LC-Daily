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
