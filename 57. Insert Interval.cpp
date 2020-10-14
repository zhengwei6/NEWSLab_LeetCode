class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if(intervals.size() == 0) return {newInterval};
        int j;
        int ans = 0;
        for(int i = 0 ; i < intervals.size() ; i++) {
            res.push_back(intervals[i]);
            if(res.back()[1] >= newInterval[0]) {
                ans = 1;
                if(res.back()[0] >  newInterval[0] && res.back()[0] > newInterval[1]) {
                    j = i;
                    res.back()[0] = newInterval[0];
                    res.back()[1] = newInterval[1];
                    break;
                }
                res.back()[0] = min(res.back()[0], newInterval[0]);
                res.back()[1] = max(res.back()[1], newInterval[1]);   
                j = i;
                for(j ; j < intervals.size() ; j++) {
                    if(res.back()[1] < intervals[j][0]) {
                        break;
                    }    
                    res.back()[1] = max(res.back()[1], intervals[j][1]);
                }
                break;
            }
            if(res.back()[0]  >= newInterval[0]) {
                ans = 1;
                cout << 123;
                res.push_back(newInterval);
                j = i;
                for(j ; j < intervals.size() ; j++) {
                    if(intervals[j][0] > res.back()[1]) {
                        break;
                    }
                    res.back()[1] = max(res.back()[1], intervals[j][1]);
                }
                break;
            }
        }
        for(j ; j < intervals.size() ; j++) {
            res.push_back(intervals[j]);
        }
        if (ans == 0) res.push_back(newInterval);
        return res;
    }
};