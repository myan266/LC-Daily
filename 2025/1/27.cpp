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
