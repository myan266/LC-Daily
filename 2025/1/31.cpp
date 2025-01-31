// last day!
class Solution {
private:
    const int di[4] = {1, -1, 0, 0};
    const int dj[4] = {0, 0, 1, -1};

    class DSU {
    public:
        vector<int> parent, size;
        
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        
        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        
        void unite(int x, int y) {
            int rootX = find(x), rootY = find(y);
            if (rootX != rootY) {
                if (size[rootX] < size[rootY]) swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
        
        int getSize(int x) {
            return size[find(x)];
        }
    };

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);
        vector<vector<int>> id(n, vector<int>(n, -1));

        // Step 1: Union-Find to group land cells into islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int index = i * n + j;
                    id[i][j] = index;

                    for (int d = 0; d < 4; d++) {
                        int ni = i + di[d], nj = j + dj[d];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            dsu.unite(index, ni * n + nj);
                        }
                    }
                }
            }
        }

        // Step 2: Find the largest existing island
        int maxIsland = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxIsland = max(maxIsland, dsu.getSize(i * n + j));
                }
            }
        }

        // Step 3: Try flipping each water cell (0) and merge neighboring islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> uniqueIslands;
                    for (int d = 0; d < 4; d++) {
                        int ni = i + di[d], nj = j + dj[d];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            uniqueIslands.insert(dsu.find(ni * n + nj));
                        }
                    }

                    int newSize = 1; // The flipped cell itself
                    for (int islandID : uniqueIslands) {
                        newSize += dsu.getSize(islandID);
                    }

                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};
