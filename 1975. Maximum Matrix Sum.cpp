class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        long long sum = 0;
        int count = 0;
        int mini = INT_MAX;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] < 0) count++;
                int val = abs(nums[i][j]);
                sum += val;
                mini = min(mini, val);
            }
        }

        if(count % 2 == 0) return sum;
        else return sum - 2LL * mini;
    }
};