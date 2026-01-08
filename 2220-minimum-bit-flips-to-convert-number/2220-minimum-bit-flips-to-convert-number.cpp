class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int count = 0;
        while(ans){
            ans = ans & (ans - 1);
            count++;
        }
        return count;
    }
};