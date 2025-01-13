class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> points(n+1, 0);
        for (vector<int> interval : shifts) {
            int mult = (interval[2] == 0 ? -1 : 1);
            points[interval[0]] += mult;
            points[interval[1] + 1] -= mult;
        }
        int sum = 0;
        vector<char> ans(n);
        for (int i = 0; i < n; i++) {
            sum = ((sum + points[i])%26 + 26) % 26;
            ans[i] = (char)((s[i] - 'a' + sum)%26 + 'a');
        }
        return string(ans.begin(), ans.end());
    }
};
