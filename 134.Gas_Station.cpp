class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0 ; i < gas.size() ; i++) {
            int sum = gas[i] - cost[i];
            if(sum < 0) continue;
            for(int j = i + 1 ; j <= gas.size() ; j++) {
                if(j == gas.size()) j = 0;
                if(j == i) return j;
                sum = sum + gas[j] - cost[j];
                if(sum < 0 && i < j) {
                    i = j;
                    break;
                }
                else if(sum < 0) {
                    return -1;
                }
            }
        }
        return -1;
    }
};