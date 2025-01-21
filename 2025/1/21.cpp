class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long ans = 0;
        for (int i = 1; i < n; i++) ans += grid[0][i];

        long long left = 0, right = ans;
        for (int i = 0; i < n - 1; i++) {
            left += grid[1][i];
            right -= grid[0][i+1];
            ans = min(ans, max(left, right));
        }

        return ans;
    }
};
