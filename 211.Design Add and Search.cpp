struct trie_node {
    trie_node *next_node[26];
    bool leaf_node;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root_node = new trie_node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int i;
        trie_node *iter_node = root_node;
        for(i = 0 ; i < word.length() ; i++) {
            if(iter_node->next_node[word[i]-'a'] == NULL) {
                iter_node->next_node[word[i]-'a'] = new trie_node();
            }
            iter_node = iter_node->next_node[word[i]-'a'];
        }
        iter_node->leaf_node = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return match(word, root_node, 0);
    }
    
    bool match(string& word, trie_node* p, int start) {
        if(start == word.length()) return p->leaf_node;
        bool find = false;
        if(word[start] == '.') {
            for(int i = 0 ; i < 26 ; i++) {
                if(p->next_node[i] != NULL) {
                    find = find | match(word, p->next_node[i], start + 1);
                }
            }
        }
        else {
            if(p->next_node[word[start] - 'a'] != NULL) {
                find = find | match(word, p->next_node[word[start] - 'a'], start + 1);
            }
        }
        return find;
    }
    
private:
    trie_node *root_node;
};