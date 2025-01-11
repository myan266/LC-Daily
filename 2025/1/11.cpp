class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if (n < k) return false;
        // find least possible k
        int cnt = 0;
        for (char c : s) cnt ^= 1 << (c-'a');
        return k >= max(1, __builtin_popcount(cnt));
    }
};
