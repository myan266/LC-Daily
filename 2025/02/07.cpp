class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colorcnt;
        unordered_map<int, int> colors; // note that using vector here would result in MLE b/c limit can be 10^9

        int n = queries.size();
        vector<int> ans(n);

        int cur = 0;
        for (int i = 0; i < n; i++) {
            int b = queries[i][0], c = queries[i][1];
            if (colors[b]) {
                colorcnt[colors[b]]--;
                if (colorcnt[colors[b]] == 0) cur--;
            }
            colors[b] = c;
            if (colorcnt[c] == 0) cur++;
            colorcnt[c]++;
            ans[i] = cur;
        }
        return ans;
    }
};
