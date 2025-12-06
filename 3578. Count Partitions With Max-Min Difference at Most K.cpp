class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const long long MOD = 1e9+7;
        int n = nums.size();
        vector<long long> dp(n+1), pre(n+1);
        multiset<int> st;

        dp[0] = pre[0] = 1;
        int l = 0;

        for (int r = 0; r < n; r++) {
            st.insert(nums[r]);

            while (*st.rbegin() - *st.begin() > k) {
                st.erase(st.find(nums[l]));
                l++;
            }

            dp[r+1] = (pre[r] - (l > 0 ? pre[l-1] : 0) + MOD) % MOD;
            pre[r+1] = (pre[r] + dp[r+1]) % MOD;
        }
        return dp[n];
    }
};