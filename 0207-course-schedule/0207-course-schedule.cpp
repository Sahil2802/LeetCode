class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build adjacency list and indegree array
        // adj[u] will store all courses that depend on course u
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Convert prerequisites list into graph representation
        // prerequisites[i] = [course, prereq] means prereq → course
        for (auto &pre : prerequisites) {
            int course = pre[0];
            int preReq = pre[1];
            adj[preReq].push_back(course); // edge from prereq to course
            indegree[course]++;            // course has one more prerequisite
        }

        // Step 2: Initialize queue with all courses having indegree = 0
        // These are the courses with no prerequisites (can be taken right away)
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Process courses in topological order
        int count = 0; // number of courses we can complete
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++; // We can take this course

            // Reduce indegree of all dependent courses
            for (int nextCourse : adj[course]) {
                indegree[nextCourse]--;
                // If indegree becomes 0, add to queue (ready to take)
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // Step 4: If we were able to complete all courses, no cycle exists
        return count == numCourses;
    }
};
