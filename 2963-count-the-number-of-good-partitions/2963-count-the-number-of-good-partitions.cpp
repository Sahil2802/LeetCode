class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;

        unordered_map<int, int> lastSeen;

        for(int i = 0; i < n; i++){
            lastSeen[nums[i]] = i;
        }

        int segments = 0;
        int maxLast = 0;

        for(int i = 0; i < n; i++){
            maxLast = max(maxLast, lastSeen[nums[i]]);

            if(i == maxLast){
                segments++;
            }
        }

        long long result = 1;
        for(int i = 0; i < segments - 1; i++){
            result = (result*2)%mod;
        }
        return result;
    }
};