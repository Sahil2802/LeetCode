class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build adjacency list + indegree array
        vector<vector<int>> adj(numCourses);   // adjacency list
        vector<int> indegree(numCourses, 0);   // indegree count

        for (auto &pre : prerequisites) {
            int course = pre[0];
            int preReq = pre[1];
            adj[preReq].push_back(course);   // prereq → course
            indegree[course]++;             // increment indegree of dependent course
        }

        // Step 2: Initialize queue with all courses having indegree = 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Perform BFS (Kahn’s Algorithm)
        vector<int> order;  // to store course order
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);   // take this course

            // Reduce indegree of neighbors
            for (int nextCourse : adj[course]) {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // Step 4: Check if all courses are taken
        if (order.size() == numCourses) {
            return order;  // valid order exists
        } else {
            return {};     // cycle exists → not possible
        }
    }
};
