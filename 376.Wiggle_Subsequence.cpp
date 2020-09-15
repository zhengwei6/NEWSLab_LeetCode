class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        int sum = 1;
        int taggle = -1;
        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] < nums[i-1] && (taggle == 1 || taggle==-1)) {
                sum += 1;
                taggle = 0;
            }
            else if(nums[i] > nums[i-1] && (taggle == 0 || taggle==-1)) {
                sum += 1;
                taggle = 1;
            } 
        }
        return sum;

    }
};