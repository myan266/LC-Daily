class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(high+1);
        int cnt = 0;

        memo[0] = 1;
        for (int i = 1; i <= high; i++) {
            if (i >= zero) memo[i] = (memo[i] + memo[i - zero]) % mod;
            if (i >= one) memo[i] = (memo[i] + memo[i - one]) % mod;
            if (i >= low) cnt = (cnt + memo[i]) % mod;
        }

        return cnt;
    }
};
