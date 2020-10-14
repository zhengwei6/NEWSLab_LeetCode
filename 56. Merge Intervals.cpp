class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        quick_sort(0, intervals.size() - 1, intervals);
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }   
        return res;
    }
    void swap(int left,int right, vector<vector<int>>& intervals) {
        vector<int> temp = intervals[left];
        intervals[left] = intervals[right];
        intervals[right] = temp;
    }
    int partition(int front, int end, vector<vector<int>>& intervals) {
        vector<int> pivot = intervals[end];
        int i = front - 1;
        int j = front;
        for(j ; j < end ; j++) {
            if(intervals[j][0] < pivot[0]) {
                i++;
                swap(i, j, intervals);
            }
        }
        i++;
        swap(i, end, intervals);
        return i;
    }
    void quick_sort(int front, int end, vector<vector<int>>& intervals) {
        if(front < end) {
            int i = partition(front, end, intervals);
            quick_sort(front, i - 1, intervals);
            quick_sort(i + 1, end, intervals);
        }
        return;
    }
};