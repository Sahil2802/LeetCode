// Disjoint Set Union (DSU) class with union by size and path compression
class DisjointSet {
public:
    vector<int> parent; // parent[i] stores the parent of node i
    vector<int> rank;   // rank[i] stores the rank of tree rooted at i (for union by rank)
    vector<int> size;   // size[i] stores the size of component rooted at i (for union by size)

    // Constructor: Initialize DSU for n nodes
    DisjointSet(int n) {
        parent.resize(n);
        rank.assign(n, 0);   // all ranks start at 0
        size.assign(n, 1);   // each node starts as its own component of size 1
        // Each node is initially its own parent (separate component)
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // Find operation with path compression.
    // Returns the representative (root) of the set containing node.
    int findPar(int node) {
        // Base case: if node is its own parent, it's the root
        if (parent[node] == node) return node;
        // Path compression: flatten the tree by pointing node directly to root
        return parent[node] = findPar(parent[node]);
    }

    // Union operation with union by size optimization.
    // Merges the sets containing u and v by attaching smaller set to larger set.
    void unionBySize(int u, int v) {
        // Find representatives of both sets
        int pu = findPar(u);
        int pv = findPar(v);
        
        // If already in same set, no union needed
        if (pu == pv) return;

        // Union by size: attach smaller tree under root of larger tree
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu]; // larger set absorbs smaller set's size
        } else {
            parent[pv] = pu;
            size[pu] += size[pv]; // larger set absorbs smaller set's size
        }
    }
};

class Solution {
    // Helper function to check if coordinates (r, c) are within grid bounds
    bool isValid(int r, int c, int n) {
        return r >= 0 && c >= 0 && r < n && c < n;
    }

public:
    // Find the size of the largest island after changing at most one 0 to 1.
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        // Initialize DSU for n×n cells (each cell gets a unique ID from 0 to n²-1)
        DisjointSet ds(n * n);

        // Four directions: up, right, down, left for exploring adjacent cells
        vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};

        // ========== Step 1: Build DSU for all existing islands (land cells = 1) ==========
        // Connect adjacent land cells into island components.
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                // Skip water cells
                if (grid[r][c] == 0) continue;

                // Convert 2D coordinate (r, c) to 1D node ID for DSU
                int node = r * n + c;
                
                // Check all 4 adjacent cells
                for (auto &d : dirs) {
                    int nr = r + d.first;   // neighbor row
                    int nc = c + d.second;  // neighbor column

                    // If neighbor is within bounds and is land, merge islands
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        int adj = nr * n + nc;
                        ds.unionBySize(node, adj);
                    }
                }
            }
        }

        int ans = 0;

        // ========== Step 2: Try flipping each 0 to 1 and calculate resulting island size ==========
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                // Skip land cells (we only flip water cells)
                if (grid[r][c] == 1) continue;

                // Track distinct neighboring island roots to avoid counting same island multiple times
                set<int> seenPar;
                
                // Check all 4 adjacent cells
                for (auto &d : dirs) {
                    int nr = r + d.first;
                    int nc = c + d.second;
                    
                    // If neighbor is within bounds and is land
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        int nid = nr * n + nc;
                        // Find the root of the neighbor's island component
                        int root = ds.findPar(nid);
                        // Add this root to our set of distinct neighboring islands
                        seenPar.insert(root);
                    }
                }

                // Calculate total size: 1 (flipped cell) + sum of all distinct neighboring island sizes
                int total = 1; // start with the flipped cell itself
                for (auto &root : seenPar) total += ds.size[root];
                
                // Update answer with the maximum possible island size
                ans = max(ans, total);
            }
        }

        // Edge case: If ans is still 0, it means the grid has no 0s (already all 1s).
        // In this case, the entire grid is one island of size n×n.
        if (ans == 0) return n * n;

        return ans;
    }
};