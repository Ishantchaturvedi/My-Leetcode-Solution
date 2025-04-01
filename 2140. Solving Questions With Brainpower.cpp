class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> res(n, 0);
        res[n-1] = questions[n-1][0];
        
        for (int i = n - 2; i >= 0; i--) {
            long long solve = questions[i][0];
            if (i + questions[i][1] + 1 < n) {
                solve += res[i + questions[i][1] + 1];
            }
            res[i] = max(solve, res[i + 1]);
        }
        
        return res[0];
    }
};