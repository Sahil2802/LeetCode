class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // Get the size of the bills array
        int n = bills.size();

        // Initialize counters for $5 and $10 bills
        int five = 0;
        int ten = 0;

        // Iterate through each bill in the bills array
        for(int i = 0; i < n; i++) {
            // If the customer pays with a $5 bill
            if(bills[i] == 5) {
                // Increment the count of $5 bills
                five++;
            }
            // If the customer pays with a $10 bill
            else if(bills[i] == 10) {
                // Check if we have a $5 bill to give as change
                if(five) {
                    // Use one $5 bill as change
                    five--;
                    // Increment the count of $10 bills
                    ten++;
                } else {
                    // If no $5 bill is available, return false
                    return false;
                }
            }
            // If the customer pays with a $20 bill
            else {
                // Check if we have both a $10 bill and a $5 bill to give as change
                if(five && ten) {
                    // Use one $10 bill and one $5 bill as change
                    five--;
                    ten--;
                }
                // Otherwise, check if we have at least three $5 bills to give as change
                else if(five >= 3) {
                    // Use three $5 bills as change
                    five -= 3;
                } else {
                    // If neither condition is met, return false
                    return false;
                }
            }
        }
        // If we successfully provided change for all customers, return true
        return true;
    }
};