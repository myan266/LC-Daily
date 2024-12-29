class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numWays(vector<string>& words, string target) {
        if (words.size()==0) return 0;
        int n = target.size(), m = words[0].size();

        vector<vector<long long>> memo(2, vector<long long>(m+1, 0));
        vector<vector<int>> freq(m, vector<int>(26, 0));

        for (int j = 0; j <= m; j++) memo[0][j] = 1;
        for (string &w : words) {
            for (int j = 0; j < m; j++) freq[j][(int)(w[j]-'a')]++;
        }

        for (int i = 1; i <= n; i++) {
            int cur_memo = i&1, prev_memo = 1 - cur_memo;
            memo[cur_memo][0] = 0;
            for (int j = 1; j <= m; j++) {
                memo[cur_memo][j] = memo[cur_memo][j-1];
                int occ = freq[j-1][(int)(target[i-1]-'a')];
                memo[cur_memo][j] = (memo[cur_memo][j] + memo[prev_memo][j-1] * occ)%mod;
            }
        }
        return memo[n&1][m];
    }
};
