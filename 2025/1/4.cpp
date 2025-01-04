class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> pref(n, vector<int>(26, 0));
        vector<pair<int, int>> occ(26, {-1, -1}); // track first and last occ

        vector<int> cur(26, 0);
        for (int i = 0; i < n; i++) {
            int idx = s[i]-'a';
            cur[idx]++;
            if (occ[idx].first < 0) occ[idx].first = i;
            else occ[idx].second = i;
            pref[i] = cur;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (occ[i].second < 0) continue;
            pref[occ[i].second][i]--;
            for (int j = 0; j < 26; j++) {
                ans += (pref[occ[i].second][j] > pref[occ[i].first][j]);
            }
        }
        return ans;
    }
};
