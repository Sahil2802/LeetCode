class Solution {
public:
    // Find operation with path compression for Disjoint Set Union (DSU).
    // Returns the representative (root/leader) of the set containing element x.
    int find(vector<int>& parent, int x) {
        // Base case: if x is its own parent, it's the root
        if (parent[x] == x)
            return x;
        // Path compression: flatten the tree by pointing x directly to root
        return parent[x] = find(parent, parent[x]);
    }

    // Union operation with union by rank optimization.
    // Merges the sets containing a and b by attaching smaller rank tree under larger rank tree.
    void unionSet(vector<int>& parent, vector<int>& rank, int a, int b) {
        // Find representatives of both sets
        int leader1 = find(parent, a);
        int leader2 = find(parent, b);

        // If already in same set, no union needed
        if (leader1 == leader2) return;

        // Attach smaller rank tree under root of larger rank tree
        if (rank[leader1] < rank[leader2]) {
            parent[leader1] = leader2;
        } else if (rank[leader1] > rank[leader2]) {
            parent[leader2] = leader1;
        } else {
            // Equal ranks: arbitrarily choose leader1 as parent and increment its rank
            parent[leader2] = leader1;
            rank[leader1]++;
        }
    }

    // Merge accounts belonging to the same person based on common email addresses.
    // Returns merged accounts with emails sorted in each account.
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        // Initialize DSU: each account starts as its own component
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }

        // Map each email to the first account index that contains it.
        // If an email appears in multiple accounts, union those accounts (same person).
        unordered_map<string, int> emailToAccount;
        for(int i = 0; i < n; i++){
            // Skip the name at index 0, process emails from index 1 onwards
            for(int j = 1; j < accounts[i].size(); j++){
                string &email = accounts[i][j];
                
                // First time seeing this email: map it to current account
                if(!emailToAccount.count(email)){
                    emailToAccount[email] = i;
                }
                else{
                    // Email already exists in another account: merge the two accounts
                    unionSet(parent, rank, i, emailToAccount[email]);
                }
            }
        }

        // Group emails by their root account (component representative).
        // All accounts merged together will have the same root.
        unordered_map<int, vector<string>> components;
        for(auto &[email, idx] : emailToAccount){
            int root = find(parent, idx);
            components[root].push_back(email);
        }

        // Build the final result: for each component, create merged account.
        vector<vector<string>> result;
        for(auto &[root, emails] : components){
            // Sort emails in lexicographic order as required
            sort(emails.begin(), emails.end());

            // Build merged account: [name, email1, email2, ...]
            vector<string> merged;
            merged.push_back(accounts[root][0]); // Add the account name
            merged.insert(merged.end(), emails.begin(), emails.end()); // Add sorted emails
            
            result.push_back(merged);
        }
        return result;
    }
};