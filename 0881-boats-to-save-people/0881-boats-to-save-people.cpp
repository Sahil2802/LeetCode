class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();

        int boats = 0;
        int l = 0, r = n - 1;
        int weightSum = 0;
        while(l <= r){
            weightSum = people[l] + people[r];
            if(weightSum <= limit){
                l++;
            }
            r--;
            boats++;
        }
        return boats;
    }
};