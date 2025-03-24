class Solution {
    public:
         vector<vector<int>> merge(vector<vector<int>> &A){
            if(A.size()<=1) return A;
            sort(A.begin(), A.end());
            vector<vector<int>> res;
            res.push_back(A[0]);
            for(int i=1; i<A.size(); i++) {
                if(res.back()[1] >= A[i][0]) res.back()[1] = max(res.back()[1] , A[i][1]);
                else res.push_back(A[i]); 
            }
            return res;
        }
        int countDays(int days, vector<vector<int>> &A){
            vector<vector<int>> newA = merge(A);
            for(vector<int> &interval : newA){
                days -= (interval[1] - interval[0] + 1);
            }
            return days;
        }
    };