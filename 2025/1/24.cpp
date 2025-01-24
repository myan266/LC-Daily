class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outDeg(n);
        vector<vector<int>> inGraph(n);
        queue<int> safe;

        for (int i = 0; i < n; i++) {
            outDeg[i] = graph[i].size();
            if (outDeg[i] == 0) safe.push(i);
            else {
                for (int j : graph[i]) inGraph[j].push_back(i);
            }
        }

        while (!safe.empty()) {
            int cur = safe.front();
            safe.pop();
            for (int i : inGraph[cur]) {
                outDeg[i]--;
                if (outDeg[i] == 0) {
                    safe.push(i);
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (outDeg[i] == 0) ans.push_back(i); 
        }
        return ans;
    }
};
