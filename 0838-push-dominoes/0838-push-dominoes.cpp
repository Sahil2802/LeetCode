class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> leftToRight(n, -1);
        vector<int> rightToLeft(n, -1);

        // closest push from left to right (->)
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'R'){
                leftToRight[i] = i;
            }
            else if(dominoes[i] == '.'){
                leftToRight[i] = (i > 0) ? leftToRight[i - 1] : -1;
            }
        }

        // closest push from right to left (<-)
        for(int i = n-1; i >= 0; i--){
            if(dominoes[i] == 'L'){
                rightToLeft[i] = i;
            }
            else if(dominoes[i] == '.'){
                rightToLeft[i] = (i < n-1) ? rightToLeft[i + 1] : -1;
            }
        }

        string result(n, '.');
        for (int i = 0; i < n; i++){
            int nearestLeft = leftToRight[i]; 
            int nearestRight = rightToLeft[i];

            if (nearestLeft == -1 && nearestRight == -1){
                result[i] = '.';
            }
            else if(nearestLeft == -1) {
                result[i] = 'L';
            }
            else if(nearestRight == -1) {
                result[i] = 'R';
            }
            else if(nearestLeft == nearestRight){
                result[i] = '.';
            }
            else{
                int distLPush = abs(i - nearestLeft);
                int distRPush = abs(i - nearestRight);
                if(distLPush == distRPush){
                    result[i] = '.';
                }
                else{
                    result[i] = (distLPush < distRPush) ? 'R' : 'L';
                }
            }
        }
        return result;
    }
};