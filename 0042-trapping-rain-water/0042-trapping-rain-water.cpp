class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 1, right = n-2;
        int leftMax = height[0], rightMax = height[n-1];

        while(left <= right){
            // condition is satisfied if the left maximum is < right maximum
            if(leftMax < rightMax){
                // we will start filling from the left as rightMax is more than leftMax
                // if element on left pointer is more than the left maximum, update leftMax. 
                if (height[left] > leftMax){
                    leftMax = height[left];
                }
                else{
                    // if not, then find the trapped water by subtracting current height[left]from leftMax
                    ans += leftMax - height[left];
                }
                left += 1;
            }
            else{
                // we will start filling from the right as leftMax is more than rightMax
                // if element on right pointer is more than the right maximum, update rightMax. 
                if(height[right] > rightMax){
                    rightMax = height[right];
                }
                else{
                    // if not, then find the trapped water by subtracting current height[left]from rightMax
                    ans += rightMax - height[right];
                }
                right -= 1;
            }
        }
        return ans;
    }
};