class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index  = nums[0];
        int save_index = 0;
        if (nums.size() == 1 && nums[0] == 0) {
            return true;
        }
        for(int i = 0 ; i < nums.size() ; i = save_index) {
            if(max_index == save_index) {
                break;
            }
            for(int j = i ; j <= max_index ; j++) {
                if(j >= nums.size()) {
                    return true;
                }
                if(nums[j]+j >= max_index) {
                    max_index = nums[j]+j;
                    save_index = j;
                }
            }
            if(max_index >= nums.size() - 1) {
                return true;
            }
            
        }
        return false;
    }
};