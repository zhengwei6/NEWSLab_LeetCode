struct trie_node {
    trie_node *next_node[26];
    int leaf_node;
};

class Trie {
public:
    /** Initialize your data structure here. */
    trie_node *root_node;
    Trie() {
        //create root node
        root_node = new trie_node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int i;
        trie_node *iter_node = root_node;
        for(i = 0 ; i < word.length() ; i++) {
            if(iter_node->next_node[word[i]-97] == NULL) break;
            iter_node = iter_node->next_node[word[i]-97];
        }
        for(int j = i ; j < word.length() ; j++) {
            // create new node
            iter_node->next_node[word[j]-97] = new trie_node();
            iter_node = iter_node->next_node[word[j]-97];
        }
        iter_node->leaf_node = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trie_node *iter_node = root_node;
        for(int i = 0 ; i < word.length() ; i++) {
            if(iter_node->next_node[word[i]-97] == NULL) return false;
            iter_node = iter_node->next_node[word[i]-97];
        }
        if(iter_node->leaf_node == 0) return false; 
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trie_node *iter_node = root_node;
        for(int i = 0 ; i < prefix.length() ; i++) {
            if(iter_node->next_node[prefix[i]-97] == NULL) return false;
            iter_node = iter_node->next_node[prefix[i]-97];
        }
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