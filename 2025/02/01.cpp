// lol indices are too boring
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool cur = !(nums[0]&1);
        for (int i : nums) {
            if ((i&1) ^ (cur ^= 1)) return 0;
        }
        return 1;
    }
};
