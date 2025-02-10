class Solution {
public:
    string clearDigits(string s) {
        int n = s.size(), len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') { // s[i] is a digit
                len = max(0, len - 1);
            }
            else {
                s[len++] = s[i];
            }
        }

        return s.substr(0, len);
    }
};
