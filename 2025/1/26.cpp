class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        vector<bool> vis(n);
        vector<vector<int>> revFav(n);
        for (int i = 0; i < n; i++) {
            revFav[fav[i]].push_back(i);
        }

        auto longestEdge = [&](int start) {
            vector<int> dist(n, 0);
            int ans = 0, avoid = fav[start];
            queue<int> bfs; bfs.push(start);

            while (!bfs.empty()) {
                int cur = bfs.front(); bfs.pop();
                int len = dist[cur];
                ans = max(ans, len);
                vis[cur] = true;
                for (int i : revFav[cur]){ 
                    if (i != avoid){ 
                        bfs.push(i); dist[i] = len + 1;
                    }
                }
            }
            return ans;
        };

        int single = 0, mult2 = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            int fast = i, slow = i;
            do {
                fast = fav[fav[fast]];
                slow = fav[slow];
                vis[fast] = vis[slow] = true;
            }
            while (fast != slow);

            fast = slow;
            int cnt = 0;
            do {
                fast = fav[fast];
                cnt++;
            } while (fast != slow);

            if (cnt == 2) 
                mult2 += longestEdge(slow) + longestEdge(fav[slow]) + 2;

            else single = max(single, cnt);
        }

        cout << single << " " << mult2 << "\n";
        return max(single, mult2);
    }
};
