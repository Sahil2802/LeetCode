class Solution {
public:
    // Function to find the length of the shortest transformation sequence from beginWord to endWord
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(), wordList.end()); // Store words for O(1) lookup
        if (!list.count(endWord)) return 0; // If endWord is not in the list, no transformation possible

        queue<pair<string, int>> q; // Queue for BFS: stores (current word, steps taken)
        q.push({beginWord, 1});     // Start BFS from beginWord with step count 1

        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();

            if(word == endWord) return steps; // Found the endWord, return the number of steps

            // Try changing each character of the current word
            for(int i = 0; i < word.size(); i++){
                string temp = word;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    temp[i] = ch; // Change the i-th character
                    // If the new word is in the list, add to queue and remove from set
                    if(list.count(temp)){
                        q.push({temp, steps + 1});
                        list.erase(temp); // Remove to prevent revisiting
                    }
                }
            }
        }
        // If endWord is not reachable, return 0
        return 0;
    }
};