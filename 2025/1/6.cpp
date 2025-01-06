class Solution {
public:
    vector<int> minOperations(string boxes) {
        int cur = 0, n = boxes.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                cur++; ans[0] += i;
            }
            if (i < n-1) ans[i+1] += 2 * cur;
        }
        for (int i = 1; i < n; i++) ans[i] += ans[i-1] - cur;
        return ans;
    }
};
