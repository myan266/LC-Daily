class Solution {
public:
    int maxScore(string s) {
        int ocnt = 0, zcnt = 0;

        int maxScore = -1000;
        for (int i = 0; i < s.size()-1; i++) {
            int curScore = (zcnt += (s[i] == '0')) - (ocnt += (s[i] == '1'));
            maxScore = max(maxScore, curScore);
        }

        return maxScore + ocnt + (s[s.size() - 1] == '1');
    }
};
