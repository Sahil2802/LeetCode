class Solution {
public:
    // Find operation with path compression for Disjoint Set Union (DSU).
    // Returns the representative (root/leader) of the set containing element x.
    int find(vector<int> &par, int x){
        // Base case: if x is its own parent, it's the root of the set
        if(par[x] == x){
            return x;
        }
        // Path compression: recursively find root and update par[x] to point directly to it.
        // This flattens the tree structure, optimizing future find operations to O(α(n)).
        return par[x] = find(par, par[x]);
    }

    // Union operation with union by rank optimization.
    // Merges the sets containing x and y by attaching the smaller tree under the larger tree's root.
    void unionSet(vector<int>&par, vector<int> &rank, int x, int y){
        // Find the representative of the set containing x
        int leader1 = find(par, x);
        // Find the representative of the set containing y
        int leader2 = find(par, y);

        // If both elements are already in the same set, no union needed
        if(leader1 == leader2) return;

        // Attach the tree with smaller rank under the tree with larger rank
        if(rank[leader1] > rank[leader2]){
            par[leader2] = leader1;
        }
        else if(rank[leader1] < rank[leader2]){
            par[leader1] = leader2;
        }
        else{
            // If ranks are equal, arbitrarily choose one as parent and increment its rank
            par[leader1] = leader2;
            rank[leader2]++;
        }
    }

    // Count the number of provinces (connected components) in the graph.
    // isConnected[i][j] = 1 means cities i and j are directly connected.
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // Initialize parent array: each city is initially its own parent (separate set)
        vector<int> par(n);
        // Initialize rank array: all trees start with rank 0
        vector<int> rank(n, 0);

        // Set each city as its own parent (each city is a separate component initially)
        for(int i = 0; i < n; i++){
            par[i] = i;
        }

        // Iterate through the upper triangle of the adjacency matrix
        // to avoid checking each connection twice
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                // If cities i and j are connected, merge their sets
                if(isConnected[i][j] == 1){
                    unionSet(par, rank, i, j);
                }
            }
        }

        // Count the number of distinct provinces (connected components).
        // A city is a root of a province if it's its own parent.
        int provinces = 0;
        for(int i = 0; i < n; i++){
            // If city i is a root (representative of its set), it represents one province
            if(find(par, i) == i){ // an element whose parent is element itself
                provinces++;
            }
        }
        return provinces;
    }
};