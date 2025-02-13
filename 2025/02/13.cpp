class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        priority_queue<long, vector<long>, greater<long>> num(nums.begin(), nums.end());

        while (num.size() >= 2 && num.top() < k) {
            long x = num.top(); num.pop();
            long y = num.top(); num.pop();
            num.push(min(x, y) * 2 + max(x, y));
            ans++;
        }
        return ans;
    }
};
