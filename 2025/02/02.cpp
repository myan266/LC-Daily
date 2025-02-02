// find inversion count (at most 1)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) cnt++;
        }
        return cnt <= 1;
    }
};


// find offset from rotation
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int offset = min_element(nums.begin(), nums.end()) - nums.begin();
        int val = offset;

        while (nums[offset] == nums[val]) {
            offset = (offset + n - 1) % n;
            if (offset == val) break;
        }
        offset = (offset + 1) % n;

        for (int i = 1; i < n; i++) {
            if (nums[(i + offset - 1) % n] > nums[(i + offset) % n]) return false;
        }
        return true;
    }
};
