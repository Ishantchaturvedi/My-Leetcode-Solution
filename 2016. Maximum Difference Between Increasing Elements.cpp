class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int curr_min = nums[0]; 
        int ret = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > curr_min) {
                ret = max(ret, nums[i] - curr_min);
            } else { 
                curr_min = min(curr_min, nums[i]);
            }
        }

        return ret;
    }
};