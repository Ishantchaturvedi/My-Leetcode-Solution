class Solution {
public:
    int partitionArray(std::vector<int>& nums, int k) {
        std::array<bool, 100001> exist = {};

        int min_val = nums[0];
        int max_val = nums[0];
        for (int num : nums) {
            min_val = std::min(min_val, num);
            max_val = std::max(max_val, num);
            exist[num] = true;
        }
        if (max_val - min_val <= k) {
            return 1;
        }
        int count_subsequences = 1;
        int cur_min = nums[0];
        int start = min_val;
        for (int i = min_val; i <= max_val; ++i) {
            if (exist[i]) {
                if (i - start > k) {
                    ++count_subsequences;
                    start = i;
                }
            }
        }
        return count_subsequences;
    }
};