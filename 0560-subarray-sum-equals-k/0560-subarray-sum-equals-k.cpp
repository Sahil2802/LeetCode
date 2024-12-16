class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumMap; // Map to store prefix sums and their counts
        int prefixSum = 0, count = 0; // Initialize the prefix sum and the count of subarrays
        sumMap[0] = 1; // Initialize the map with a prefix sum of 0

        // Iterate over the array
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i]; // Add the current element to the prefix sum
            int remove = prefixSum - k; // Calculate the target prefix sum that, when subtracted from the current prefixSum, results in the desired sum k

            // Check if the target prefix sum exists in the map
            if (sumMap.find(remove) != sumMap.end()) {
                count += sumMap[remove]; // Add the count to the number of times the target prefix sum has occurred
            }

            sumMap[prefixSum]++; // Update the count of the current prefix sum in the map
        }

        return count; 
    }
};

