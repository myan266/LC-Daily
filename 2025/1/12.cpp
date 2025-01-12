class Solution {
public:
    bool canBeValid(string s, string locked) {
        int left = 0, right = 0, leftfree = 0, rightfree = 0, n = s.size();
        // change right into left
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') left++;
            else {
                if (locked[i] == '0') rightfree++;
                right++;
            }
            if (right > left) {
                if (rightfree) {
                    left++; right--; rightfree--;
                }
                else return false;
            }
        }
        if ((left & 1) != (right & 1)) return false;
        if (left == right) return true;

        // change left into right
        left = 0, right = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == ')' ) right++;
            else {
                if (locked[i] == '0') leftfree++;
                left++;
            }
            if (left > right) {
                if (leftfree) {
                    left--; right++; leftfree--;
                }
                else return false;
            }
        }
        return true;
    }
};
