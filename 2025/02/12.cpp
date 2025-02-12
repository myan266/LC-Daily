class Solution {
private:
    int digitSum(int n) {
        int ans = 0;
        while (n) {
            ans += n%10;
            n/=10;
        }
        return ans;
    }
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> maxnum;

        for (int i : nums) {
            int dig = digitSum(i);
            if (maxnum[dig]) ans = max(ans, i + maxnum[dig]);
            maxnum[dig] = max(maxnum[dig], i);
        }
        return ans;
    }
};
