class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        // Step 1: Build the reverse graph + out-degree array
        // reverse graph: for each edge u → v in original, add v → u in reversed
        vector<vector<int>> revGraph(n);
        vector<int> outDegree(n, 0);

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);   // reverse edge
            }
            outDegree[u] = graph[u].size(); // number of outgoing edges from u
        }

        // Step 2: Initialize queue with terminal nodes (out-degree = 0)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: BFS (Kahn’s algorithm style)
        // safe[i] = true if node i is eventually safe
        vector<bool> safe(n, false);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // this node is safe (because it led to a terminal node)
            safe[node] = true;

            // check all predecessors of this node in the reversed graph
            for (int prev : revGraph[node]) {
                outDegree[prev]--;  // one outgoing edge from prev is now resolved
                if (outDegree[prev] == 0) {
                    // if prev has no more outgoing edges, it is safe
                    q.push(prev);
                }
            }
        }

        // Step 4: Collect all safe nodes
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                result.push_back(i);
            }
        }

        return result;  // already in ascending order
    }
};
