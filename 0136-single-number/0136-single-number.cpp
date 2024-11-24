class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(); 

        map<int, int> freq; // Initialize a map to count the frequency of each number

        // Count the occurrences of each number in the map
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Find the number that appears only once
        for (auto it : freq) {
            if (it.second == 1) {
                return it.first; // Return the number that appears only once
            }
        }

        return 0;
    }
};
