class Solution {
public:
    // Find operation with path compression for Disjoint Set Union (DSU).
    // Returns the representative (root/leader) of the set containing element x.
    int find(vector<int> &par, int x){
        // Base case: if x is its own parent, it's the root
        if(par[x] == x) return x;
        // Path compression: flatten the tree by pointing x directly to root
        return par[x] = find(par, par[x]);
    }

    // Union operation with union by rank optimization.
    // Merges the sets containing x and y by attaching smaller rank tree under larger rank tree.
    void unionSet(vector<int>& par, vector<int>& rank, int x, int y){
        // Find representatives of both sets
        int leader1 = find(par, x);
        int leader2 = find(par, y);

        // If already in same set, no union needed
        if(leader1 == leader2) return;

        // Attach smaller rank tree under root of larger rank tree
        if(rank[leader1] > rank[leader2]){
            par[leader2] = leader1;
        }
        else if(rank[leader1] < rank[leader2]){
            par[leader1] = leader2;
        }
        else{
            // Equal ranks: arbitrarily choose leader2 as parent and increment its rank
            par[leader1] = leader2;
            rank[leader2]++;
        }
    }

    // Determine minimum number of operations to connect all computers.
    // Returns -1 if impossible (not enough cables), otherwise returns operations needed.
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        
        // To connect n computers, we need at least n-1 cables.
        // If we have fewer cables, it's impossible to connect all computers.
        if(m < n - 1) return -1;

        // Initialize DSU: each computer starts as its own component
        vector<int> par(n), rank(n, 0);
        for(int i = 0; i < n; i++) par[i] = i;

        // Process all existing connections: merge connected computers into same component
        for(auto &edge : connections){
            unionSet(par, rank, edge[0], edge[1]);
        }

        // Count the number of disconnected components.
        // A computer is a component root if it's its own parent.
        int components = 0;
        for(int i = 0; i < n; i++){
            if(find(par, i) == i)
                components++;
        }
        
        // To connect k components, we need k-1 operations (cables).
        return components - 1;
    }
};