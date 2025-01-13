class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            else ans += 2 - (cnt[i]&1);
        }
        return ans;
    }
};
