class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st; // Unordered set to store unique elements
        int n = nums.size(); 

        if (n == 0) return 0; // If the array is empty, return 0

        // Insert all elements of the array into the set
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        int longestConsecutive = 1; // Initialize the longest consecutive sequence length

        // Iterate through each element in the array
        for (auto num : nums) {
            // Check if the current number is the start of a sequence (skip if current element is not the start of the set)
            if (st.find(num - 1) == st.end()) {
                int currConsecutive = 1; // Initialize the current consecutive sequence length
                // Increment current cnosecutive length if you find the next element of num
                while (st.find(num + 1) != st.end()) {
                    currConsecutive++;
                    num++;
                }
                // Update the longest consecutive sequence length
                longestConsecutive = max(longestConsecutive, currConsecutive);
            }
        }
        return longestConsecutive; 
    }
};