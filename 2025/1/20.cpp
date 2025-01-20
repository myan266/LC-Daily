class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), p = arr.size();
        vector<int> rev(p + 1);
        for (int i = 0; i < p; i++) rev[arr[i]] = i;

        int ans = p + 1;
        // rows
        for (int i = 0; i < m; i++) {
            int cur = rev[mat[i][0]];
            for (int j = 0; j < n; j++) cur = max(cur, rev[mat[i][j]]);
            ans = min(ans, cur);
        }
        // cols
        for (int j = 0; j < n; j++) {
            int cur = rev[mat[0][j]];
            for (int i = 0; i < m; i++) cur = max(cur, rev[mat[i][j]]);
            ans = min(ans, cur);
        }

        return ans;
    }
};
