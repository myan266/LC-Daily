class Solution {
private:
    bool isPreAndSuf(string& a, string& b) {
        int m = a.size(), n = b.size();
        if (m > n) return false;
        for (int i = 0; i < m; i++) {
            if (a[i] != b[i]) return false;
            if (a[m - 1 - i] != b[n - 1 - i]) return false;
        }
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += isPreAndSuf(words[i], words[j]);
            }
        }
        return ans;
    }
};
