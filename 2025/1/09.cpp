class Solution {
private:
    bool isPref(string& word, string& pref, int &m) {
        if (word.size() < m) return false;
        for (int i = 0; i < m; i++) {
            if (word[i] != pref[i]) return false;
        }
        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0, m = pref.size();
        for (string &w : words) {
            ans += isPref(w, pref, m);
        }
        return ans;
    }
};
