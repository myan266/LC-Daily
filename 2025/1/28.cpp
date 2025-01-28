class Solution {
public:
    pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        queue<int> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;

                int cur = grid[i][j];
                grid[i][j] = 0;

                que.push(i*n+j);
                while (!que.empty()) {
                    int cd = que.front(); que.pop();
                    int ci = cd/n, cj = cd%n;
                    for (int d = 0; d < 4; d++) {
                        int ni = ci + dir[d].first, nj = cj + dir[d].second;
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] == 0) continue;
                        cur += grid[ni][nj];
                        grid[ni][nj] = 0;
                        que.push(ni*n + nj);
                    }
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
