class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; i++) sortedNums[i] = {nums[i], i};

        sort(sortedNums.begin(), sortedNums.end());

        vector<int> indices, vals;

        vals.push_back(sortedNums[0].first);
        indices.push_back(sortedNums[0].second);

        for (int i = 1; i < n; i++) {
            if (sortedNums[i].first - sortedNums[i - 1].first > limit) {
                sort(indices.begin(), indices.end());
                for (int j = 0; j < indices.size(); j++) nums[indices[j]] = vals[j];
                indices.clear(); vals.clear();
            }
            indices.push_back(sortedNums[i].second);
            vals.push_back(sortedNums[i].first);
        }
        sort(indices.begin(), indices.end());
        for (int j = 0; j < indices.size(); j++) nums[indices[j]] = vals[j];
        return nums;
    }
};
