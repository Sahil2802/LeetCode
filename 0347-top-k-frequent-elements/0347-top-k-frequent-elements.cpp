class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // store the frequency of each elements in map
        unordered_map <int, int> ump;
        for (int i = 0; i < nums.size(); i++){
            ump[nums[i]]++;
        }

        // store the element-frequency pair (Max-Heap) in the priority queue
        priority_queue <pair<int, int>> pq;
        for (auto x : ump){
            pq.push({x.second, x.first});
        }
        vector <int> ans;
        // Remove the top or root of Priority Queue K times and print the element.
        while (k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};