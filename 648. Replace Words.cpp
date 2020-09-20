struct TrieNode {
    TrieNode *child_node[26];
    bool leaf_node;
};
class Solution {
public:
    void init_dict(vector<string>& dictionary) {
        root_node = new TrieNode();
        for(int i = 0 ; i < dictionary.size() ; i++) {
            TrieNode *iter_node = root_node;
            for(int j = 0 ; j < dictionary[i].length() ; j++) {
                if(iter_node->child_node[dictionary[i][j] - 'a'] != NULL) {
                    iter_node = iter_node->child_node[dictionary[i][j] - 'a'];
                }
                else {
                    iter_node->child_node[dictionary[i][j] - 'a'] = new TrieNode();
                    iter_node = iter_node->child_node[dictionary[i][j] - 'a'];
                } 
            }
            iter_node->leaf_node = true;
        }
        return;
    }
    
    string match(string &match_string) {
        string ans = "";
        TrieNode *iter_node = root_node;
        int i;
        int first_index = 0;
        for(i = 0 ; i < match_string.length() ; i++) {
            if(iter_node->child_node[match_string[i] - 'a'] != NULL) {
                if(iter_node->child_node[match_string[i] - 'a']->leaf_node == true) {
                    ans = match_string.substr(first_index, i - first_index + 1);
                    break;    
                }
                iter_node = iter_node->child_node[match_string[i] - 'a'];
            }
            else {
                break;
            }
        }
        return ans;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";
        int current = 0;
        int next;
        init_dict(dictionary);
        while(1) {
            next = sentence.find_first_of(" ", current);
            if(next != current) {
                string tmp = sentence.substr(current, next - current);
                string replace_str = match(tmp);
                if(replace_str.length() == 0 && current != 0) {
                    ans = ans + " " + tmp;
                }
                else if(current != 0) {
                    ans = ans + " " + replace_str;
                }
                else if(replace_str.length() == 0) {
                    ans = ans + tmp;
                }
                else{
                    ans = ans + replace_str;
                }
            }
            if (next == string::npos) break;
            current = next + 1;
        }
        return ans;
    }
private:
    TrieNode *root_node;
};