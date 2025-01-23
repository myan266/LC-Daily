class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            int cur = 0;
            int lastj = -1;
            for (int j = 0; j < n; j++) {
                if (grid[i][j]){ 
                    cur++; lastj = j;
                }
            }
            if (cur > 1) ans += cur;
            else if (cur == 1) {
                for (int j = 0; j < m; j++) {
                    if (j != i && grid[j][lastj]) {
                        ans++; break;
                    }
                }
            }
        }
        return ans;
    }
};
