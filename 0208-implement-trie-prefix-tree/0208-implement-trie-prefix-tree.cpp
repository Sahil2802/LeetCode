class TrieNode {
public:
    // Array to store pointer to child nodes
    TrieNode* children[26];
    // flag to represent the end of a word
    bool isWord;

    TrieNode(){
        // Initialize all children as NULL
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        // Initialize isWord flag as false
        isWord = false;
    }
}; 

class Trie {
public:
    // Pointer to the root node of the trie
    TrieNode* root;
    Trie() {
        // Initialise the Trie with empty root node
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        int curr = 0;

        for (int i = 0; i < word.size(); i++){
            // Calculate the index of the character in the children array
            curr = word[i] - 'a';
            // Create a new node if the child does not exist
            if (node->children[curr] == NULL){
                node->children[curr] = new TrieNode();
            }

            // Traverse to the child node
            node = node->children[curr];
        }
        // Mark the last node(word) as the end of the string
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        int curr = 0;

        for (int i = 0; i < word.size(); i++){
            // Calculate the index of the character in the children array
            curr = word[i] - 'a';
            // Return false if any character does not exist in the trie
            if (node->children[curr] == NULL){
                return false;
            }
            // Traverse to the child node
            node = node->children[curr];
        }
        // Return true if the last node represents the end of a word
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < prefix.size(); i++){
            // Calculate the index of the character in the children array
            curr = prefix[i] - 'a';
            // Return false if any character does not exist in the trie
            if (node->children[curr] == NULL){
                return false;
            }
            // Traverse to the child node
            node = node->children[curr];
        }
        // Return true if the prefix exists in the trie
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */