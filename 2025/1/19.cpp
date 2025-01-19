class Solution {
private:
    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>> minHeap;

        for (int i = 0; i < m; ++i) {
            minHeap.emplace(-heightMap[i][0], i, 0);
            minHeap.emplace(-heightMap[i][n - 1], i, n - 1);
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            minHeap.emplace(-heightMap[0][j], 0, j);
            minHeap.emplace(-heightMap[m - 1][j], m - 1, j);
            visited[0][j] = visited[m - 1][j] = true;
        }

        int waterTrapped = 0;
        while (!minHeap.empty()) {
            auto [curHeight, x, y] = minHeap.top();
            curHeight *= -1;
            minHeap.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    waterTrapped += max(0, curHeight - heightMap[nx][ny]);
                    minHeap.emplace(-1 * max(curHeight, heightMap[nx][ny]), nx, ny);
                }
            }
        }
        return waterTrapped;
    }
};
