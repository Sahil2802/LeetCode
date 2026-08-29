class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = (long)sqrt(c); // right starts at the largest possible value

        while (left <= right) {
            long sum = left * left + right * right; // use long to avoid overflow

            if (sum == c) {
                return true; // found a valid pair (a=left, b=right)
            }
            else if (sum > c) {
                right--; // sum too big, decrease it
            }
            else {
                left++; // sum too small, increase it
            }
        }

        return false; // no valid pair found
    }
};