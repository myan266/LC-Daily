class Solution {
public:
    int maxScore(string s) {
        int ocnt = count(s.begin(), s.end(), '1'), zcnt = 0;

        int maxScore = 0;
        for (int i = 0; i < s.size()-1; i++) {
            int curScore = (zcnt += (s[i] == '0')) + (ocnt -= (s[i] == '1'));
            maxScore = max(maxScore, curScore);
        }

        return maxScore;
    }
};
