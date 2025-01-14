class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int64_t occA = 0ll, occB = 0ll;
        int n = A.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            occA |= (1ll << A[i]);
            occB |= (1ll << B[i]);
            ans[i] = __builtin_popcountll((occA & occB));
        }
        return ans;
    }
};
