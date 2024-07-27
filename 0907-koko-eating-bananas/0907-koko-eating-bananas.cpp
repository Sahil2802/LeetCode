class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = 1;
        for(int pile: piles){
            r = max(pile, r);
        }

        while(l < r){
            int mid = l + (r - l)/2;
            int time = 0;
            for(int pile: piles){
                time += ceil(pile * 1.0/mid);
            }
            if(time <= h){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
        
    }
};