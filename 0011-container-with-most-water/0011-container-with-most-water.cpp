class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        // Two Pointer Approach
        while (left < right){
            //  widht * height
            int area = (right - left) * min(height[left], height[right]);
            maxArea = max(area, maxArea);
            
            if (height[left] < height[right]){
                left++;
            }
            else {
                right--;
            }
        }
        return maxArea; 
    }
};