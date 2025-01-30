class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (const vector<int>& e : edges) {
            int u = e[0] - 1, v = e[1] - 1; // Convert to 0-based index
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 1: Check bipartiteness and get connected components
        vector<int> label(n, 0);  // 0 = unvisited, 1 & 2 are bipartite colors
        vector<vector<int>> components;
        for (int i = 0; i < n; i++) {
            if (label[i]) continue;  // Skip already visited nodes
            
            queue<int> q;
            q.push(i);
            label[i] = 1;
            vector<int> component = {i};
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!label[v]) {
                        label[v] = 3 - label[u];  // Assign opposite color
                        q.push(v);
                        component.push_back(v);
                    } else if (label[v] == label[u]) {
                        return -1;  // Graph is not bipartite
                    }
                }
            }
            components.push_back(component);
        }

        // Step 2: Find max depth for each component
        auto bfs = [&](int start) -> int {
            queue<int> q;
            vector<int> dist(n, -1);
            q.push(start);
            dist[start] = 0;
            int maxDist = 0;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        if (dist[v] > maxDist) {
                            maxDist = dist[v];
                        }
                    }
                }
            }
            return maxDist;
        };

        int result = 0;
        for (const auto& comp : components) {
            int maxDiameter = 0;
            for (int node : comp) {
                maxDiameter = max(maxDiameter, bfs(node));
            }
            result += maxDiameter + 1;
        }

        return result;
    }
};
