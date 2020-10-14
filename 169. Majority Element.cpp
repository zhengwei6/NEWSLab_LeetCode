class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        int s = nums.size();
        for(int i=0;i<s;i++)
        {
            if(++hash[nums[i]] > s/2)
                return nums[i];
        }
        return -1;
    }
};