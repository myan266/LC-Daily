class Solution {
private:
    pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    // recognize that the minimum path will never visit the same cell twice
    // and that it is always possible
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> memo(m * n, 500); // // encode as i * n + j

        auto in_bound = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < m && j < n;
        };

        queue<int> que; // encode as i * n + j
        que.push(0);
        memo[0] = 0;

        while (!que.empty()) {
            int idx = que.front();
            int i = idx/n, j = idx%n;
            que.pop();
            for (int d = 0; d < 4; d++) {
                int cost = memo[idx] + ((d + 1) != grid[i][j]);
                int ni = i + dir[d].first, nj = j + dir[d].second;
                int nidx = ni * n + nj;
                if (in_bound(ni, nj) && (cost < memo[nidx])) {
                    que.push(nidx);
                    memo[nidx] = cost;
                }
            }
        }

        return memo[m*n - 1];
    }
};
