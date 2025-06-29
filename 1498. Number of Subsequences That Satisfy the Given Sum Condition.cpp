class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0;
        int n = nums.size();
        int mod = 1e9 + 7;

        // Precompute powers of 2 up to n: pows[i] = 2^i % mod
        vector<int> pows(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pows[i] = (pows[i - 1] << 1) % mod;  // same as (pows[i - 1] * 2) % mod
        }

        // Sort the input array to use two-pointer approach
        sort(nums.begin(), nums.end());

        // Two pointers from both ends
        int l = 0, r = n - 1;
        while (l <= r) {
            // If the smallest + largest > target, reduce max
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                // If valid: All subsequences from l to r are valid
                res = (res + pows[r - l]) % mod;
                l++;
            }
        }

        return res;
    }
};