class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> extra;
        for (int i = 0; i < n; i++) extra[nums[i] - i]++;

        long long ans = ((long long) n) * (n - 1) / 2;
        for (auto &[key, val] : extra) ans -= ((long long)val) * (val - 1) / 2;

        return ans;
    }
};
