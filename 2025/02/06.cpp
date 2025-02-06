class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> occ;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) occ[nums[i]*nums[j]]++;
        }

        int ans = 0;
        for (auto &[key, val] : occ){ 
            ans += val * (val - 1) / 2 * 8;
        }
        return ans;
    }
};
