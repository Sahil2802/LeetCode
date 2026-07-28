class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> leftToRight(n, -1); // nearest R to the left of each index
        vector<int> rightToLeft(n, -1); // nearest L to the right of each index

        // Scan left to right: propagate nearest R forward
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R')
                leftToRight[i] = i;                                    // R found, mark itself
            else if (dominoes[i] == '.')
                leftToRight[i] = (i > 0) ? leftToRight[i - 1] : -1;  // inherit from left neighbor
            // 'L' breaks the R propagation, stays -1
        }

        // Scan right to left: propagate nearest L backward
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L')
                rightToLeft[i] = i;                                      // L found, mark itself
            else if (dominoes[i] == '.')
                rightToLeft[i] = (i < n - 1) ? rightToLeft[i + 1] : -1; // inherit from right neighbor
            // 'R' breaks the L propagation, stays -1
        }

        string result(n, '.');
        for (int i = 0; i < n; i++) {
            int nearestLeft  = leftToRight[i]; // index of nearest R pushing from left
            int nearestRight = rightToLeft[i]; // index of nearest L pushing from right

            if (nearestLeft == -1 && nearestRight == -1)
                result[i] = '.';              // no force from either side
            else if (nearestLeft == -1)
                result[i] = 'L';              // only L force from right, no R from left
            else if (nearestRight == -1)
                result[i] = 'R';              // only R force from left, no L from right
            else if (nearestLeft == nearestRight)
                result[i] = '.';              // same domino, already pushed (edge case)
            else {
                int distLPush = abs(i - nearestLeft);  // distance to nearest R on left
                int distRPush = abs(i - nearestRight); // distance to nearest L on right
                if (distLPush == distRPush)
                    result[i] = '.';                               // equal forces, balanced
                else
                    result[i] = (distLPush < distRPush) ? 'R' : 'L'; // closer force wins
            }
        }
        return result;
    }
};