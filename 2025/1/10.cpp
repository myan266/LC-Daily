class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> targ(26), cur(26);
        for (string& w : words2) {
            for (char c : w) cur[c - 'a']++;
            for (int i = 0; i < 26; i++){ 
                targ[i] = max(targ[i], cur[i]);
                cur[i] = 0;
            }
        }
        for (string& w : words1) {
            for (char c : w) cur[c - 'a']++;
            bool res = true;
            for (int i = 0; i < 26; i++) {
                res &= (cur[i] >= targ[i]);
                cur[i] = 0;
            }
            if (res) ans.push_back(w);
        }
        return ans;
    }
};
