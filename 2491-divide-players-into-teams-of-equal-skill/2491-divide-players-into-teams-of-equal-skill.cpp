class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        // Step 1: count each skill value and compute the total skill
        long long totalSum = 0;
        vector<int> freq(1001, 0); // freq[v] = number of players with skill v (v up to 1000)
        for(int rep : skill){
            totalSum += rep;
            freq[rep]++;
        }

        // Step 2: every team has the same sum, so total = target * (n/2)
        if(totalSum % (n/2) != 0) return -1; // can't split evenly across teams
        int target = totalSum / (n/2); // required skill sum per team

        // Step 3: pair smallest remaining skill with largest remaining skill
        long long totalChemistry = 0;
        int l = 0, r = 1000;  // l = smallest skill, r = largest skill
        while(l <= r){ // <= so the l == r (same skill) case is processed
            while(l <= r && freq[l] == 0) l++; // skip skill values nobody has (left side)
            while(l <= r && freq[r] == 0) r--; // skip skill values nobody has (right side)
            if(l > r) break; // everyone has been paired

            // pair must be equal to the target, and both groups must be the same size
            if(l + r != target || freq[l] != freq[r]) return -1;

            if(l == r){
                if(freq[l] % 2 != 0) return -1; // odd count: one player has no partner
                totalChemistry += (long long)l * l * (freq[l] / 2); // all players here have the same skill, 2 per team, so freq[l] / 2 teams
            }
            else{
                totalChemistry += (long long)l * r * freq[l]; // l and r are different skills, 1 of each per team, so freq[l] teams. And just freq[l] because freq are equal at this point.
            }
            l++;                                     
            r--;
        }
        return totalChemistry;
    }
};