class Solution {
public:
    void subsetsUtil(vector<int>& A, vector<vector<int> >& res,vector<int>& subset, int index)
    {
        res.push_back(subset);
        for (int i = index; i < A.size(); i++) {
            subset.push_back(A[i]);
            subsetsUtil(A, res, subset, i + 1);
            subset.pop_back();
        }
    
        return;
    }

    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<int> subset;
        vector<vector<int> > res;
        int index = 0;
        subsetsUtil(A, res, subset, index);
    
        return res;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int i, j, x_or=0, max=0, count=0;
        vector<vector<int> > res = subsets(nums);
        for(i=0 ; i<res.size() ; i++)
        {
            x_or = 0;
            for(j=0 ; j<res[i].size() ; j++)
            {
                x_or |=res[i][j];
            }
            if(x_or>max)
            {
                max = x_or;
                count=1;
            }
            else if(x_or==max)
            {
                count++;
            }
        }
        return count;
    }
};