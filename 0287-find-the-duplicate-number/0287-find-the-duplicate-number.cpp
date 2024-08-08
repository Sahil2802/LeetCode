class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize the slow and fast pointers
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        // Pass 1: Find the intersection point of the two pointers
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        // Pass 2: Find the entrance to the cycle (the duplicate number)
        slow = 0; // Reset slow pointer to the start
        while (slow != fast) {
            slow = nums[slow]; // Move both pointers one step at a time
            fast = nums[fast]; // Move both pointers one step at a time
        }
        // The point where they meet is the duplicate number
        return slow;
    }
};