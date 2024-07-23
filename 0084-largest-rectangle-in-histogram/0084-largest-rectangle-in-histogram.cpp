class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int max_area = 0;

        for(int i = 0; i < heights.size(); i++){
            // While the current bar is shorter than the bar at the stack's top index
            while (st.top() != -1 && heights[st.top()] >= heights[i]){
                int height = heights[st.top()];
                st.pop(); // Remove the top index after copying it
                int width;
                // If stack is empty, the width is the current index
                if (st.empty()) width = i;
                // Otherwise, the width is the difference between the current index and the new top index minus one
                else width = i - st.top() - 1;
                // Calculate the area for the rectangle with the height of the bar at the stack's top index
                max_area = max(max_area, height * width);
            }
            // Push the current index onto the stack
            st.push(i);
        }

        // Process any remaining bars in the stack i.e. These elements represent heights for which no smaller heights were found to the right
        while(st.top() != -1){
            int height = heights[st.top()];
            st.pop();
            int width = heights.size() - st.top() - 1;
            // Update the maximum area
            max_area = max(max_area, height * width);
        }

        return max_area;
    }
};