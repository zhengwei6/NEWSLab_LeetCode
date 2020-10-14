class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size() == 0) return 0;
        vector<int> count(26, 0);
        int max_count = 0;
        int common_num = 0;
        int kind = 0;
        for(int i = 0 ; i < tasks.size() ; i++) {
            count[tasks[i] - 'A'] += 1;
        }
        for(int i = 0 ; i < 26 ; i++) {
            if(count[i] >= max_count) max_count = count[i];
            if(count[i] > 0) kind += 1;
        }
        for(int i = 0 ; i < 26 ; i++) {
            if(count[i] == max_count) common_num += 1; 
        }
        cout << kind << " "<< max_count << " "<< common_num << endl;
        int i = tasks.size();
        return max(i, (n+1) * (max_count - 1) + common_num);
    }
};