class Solution {
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // find the manhattan distance to the closest water cell
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        // i * n + j
        queue<int> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]){ 
                    que.push(i*n+j);
                    ans[i][j] = 0;
                }
            }
        }

        auto in_bound = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < m && j < n;
        };

        while (!que.empty()) {
            int idx = que.front();
            que.pop();
            int ci = idx/n, cj = idx%n;
            for (int i = 0; i < 4; i++) {
                int ni = ci + dx[i], nj = cj + dy[i];
                if (in_bound(ni, nj) && ans[ni][nj] == -1) {
                    que.push(ni*n + nj);
                    ans[ni][nj] = ans[ci][cj] + 1;
                }
            }
        }
        return ans;
    }
};
