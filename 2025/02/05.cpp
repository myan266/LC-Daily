class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m != n) return false;
        int first = -1, second = -1;
        for (int i = 0; i < m; i++) {
            if (s1[i] != s2[i]) {
                if (first == -1) first = i;
                else {
                    if (second == -1) second = i;
                    else return false;
                }
            }
        }
        return first == -1 || (second != -1 && s1[first] == s2[second] && s1[second] == s2[first]);
    }
};
