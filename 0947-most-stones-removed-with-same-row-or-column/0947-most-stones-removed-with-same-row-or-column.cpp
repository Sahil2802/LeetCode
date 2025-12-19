// Disjoint Set Union (DSU) / Union-Find data structure
class DisjointSet{
public:
    vector<int> parent;  // parent[i] stores the parent of node i
    vector<int> size;    // size[i] stores the size of component with root i

    // Constructor: Initialize DSU with n nodes
    // Initially, each node is its own parent (separate component)
    DisjointSet(int n){
        size.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;  // Each node is its own parent initially
            size[i] = 1;    // Each component has size 1 initially
        }
    }

    // Find the ultimate parent (root) of a node with path compression
    // Path compression: makes all nodes point directly to root for faster future queries
    int findPar(int node){
        if(parent[node] == node){
            return node;  // Base case: node is its own parent (root)
        }
        // Recursively find root and compress path by directly linking to root
        return parent[node] = findPar(parent[node]);
    }

    // Union two nodes by size (attach smaller component to larger one)
    // This keeps the tree height balanced for better performance
    void unionBySize(int u, int v){
        int pu = findPar(u);  // Find root of u's component
        int pv = findPar(v);  // Find root of v's component
        
        if(pu == pv) return;  // Already in same component, nothing to do

        // Attach smaller component to larger component
        if(size[pu] < size[pv]){
            parent[pu] = pv;        // Make pv parent of pu
            size[pv] += size[pu];   // Update size of merged component
        }
        else{
            parent[pv] = pu;        // Make pu parent of pv
            size[pu] += size[pv];   // Update size of merged component
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);

        // Build graph: connect stones that share same row or column
        // If two stones share row/col, they're in the same connected component
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // stones[i][0] = row, stones[i][1] = column
                // If stones share row (x-coordinate) or column (y-coordinate)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ds.unionBySize(i, j);  // Union them into same component
                }
            }
        }

        // Count number of connected components
        // Each component can be reduced to 1 stone
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findPar(i) == i) {
                components++;  // Node i is a root, so it's a unique component
            }
        }
        
        // Maximum stones removable = total stones - number of components
        // Explanation: From each component, exactly 1 stone must remain
        return n - components;
    }
};