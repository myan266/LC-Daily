// O(N) with prefix sum
class Solution {
private:
    bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pref(words.size()+1, 0);
        for (int i = 1; i <= words.size(); i++) 
            pref[i] = pref[i-1] + (isVowel(words[i-1][0]) && isVowel(words[i-1][words[i-1].size()-1]));

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = pref[queries[i][1]+1] - pref[queries[i][0]];
        }
        return ans;
    }
};

// O(log N) with sparse table
class Solution {
private:
    const int K = 20;
    vector<vector<int>> st;

    bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int query(int L, int R) {
        int sum = 0;
        for (int i = K; i >= 0; i--) {
            if ((1 << i) <= R - L + 1) {
                sum += st[i][L];
                L += 1 << i;
            }
        }
        return sum;
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();
        st.assign(K, vector<int>(n));

        for (int i = 0; i < n; i++) st[0][i] = isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1]);
        for (int i = 1; i <= K; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = st[i-1][j] + st[i-1][j + (1 << (i - 1))];
            }
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < m; i++) ans[i] = query(queries[i][0], queries[i][1]);
        return ans;
    }
};
