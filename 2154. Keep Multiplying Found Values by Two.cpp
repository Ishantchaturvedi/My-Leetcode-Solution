class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int cnt[1001] = {0};
        for (int &x : nums) {
            cnt[x]++;
        }        
        while (original <= 1000 && cnt[original] > 0) {
            original *= 2;
        }
        return original;
    }
};