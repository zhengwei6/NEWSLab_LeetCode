class Solution {
public:
    int find_max_sequence1(int start, int end, vector<int>& nums) {
        int max_sum = nums[end];
        int sum = 0;
        for(int i = end ; i >= start ; i--) {
            sum += nums[i];
            if(max_sum < sum) {
                max_sum = sum;
            }
        }
        return max_sum;
    }
    
    int find_max_sequence2(int start, int end, vector<int>& nums) {
        int max_sum = nums[start];
        int sum = 0;
        for(int i = start ; i <= end ; i++) {
            sum += nums[i];
            if(max_sum < sum) {
                max_sum = sum;
            }
        }
        return max_sum;
    }
    
    int maxSubArray(vector<int>& nums) {
        return maxSubArray2(0, nums.size() - 1, nums);
    }
    
    int maxSubArray2(int start, int end, vector<int>& nums) {
        int m1, m2, m3, m4;
        if(end == start) {
            return nums[start];
        }
        m1 = maxSubArray2(start, (start + end)/2, nums);
        m2 = maxSubArray2((start + end)/2 + 1, end, nums);
        m3 = find_max_sequence1(start, (start + end)/2, nums);
        m4 = find_max_sequence2((start + end)/2 + 1, end, nums);
        if((m3 + m4) >= m1 && (m3 + m4) >= m2) {
            return m3 + m4;
        }
        else if(m2 >= m1 && m2 >= (m3 + m4)) {
            return m2;
        }
        return m1;
    }
};