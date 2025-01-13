class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        int ans = 0;
        long long pref = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            pref += 2 * nums[i];
            if (pref >= sum) ans++;
        }
        return ans;
    }
};
