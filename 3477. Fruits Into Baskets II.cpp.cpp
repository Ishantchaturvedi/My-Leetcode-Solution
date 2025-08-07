class Solution {
public:
vector<vector<int>>t;
int solve(int i,int j,vector<vector<int>>&fruits){
    
    if(i>=fruits.size()||i<0||j>=fruits.size()||j<0||i>=j)
    {
        return 0;
    }
    if(t[i][j]!=-1)
    {
        return t[i][j];
    }
    int leftd=fruits[i][j]+solve(i+1,j-1,fruits);
    int rightd=fruits[i][j]+solve(i+1,j+1,fruits);
    int down=fruits[i][j]+solve(i+1,j,fruits);
    return t[i][j]=max(leftd,max(rightd,down));
}
int solve2(int i,int j,vector<vector<int>>&fruits){
    
    if(i>=fruits.size()||i<0||j>=fruits.size()||j<0||i<=j)
    {
        return 0;
    }
    if(t[i][j]!=-1)
    {
        return t[i][j];
    }
    int upd=fruits[i][j]+solve2(i-1,j+1,fruits);
    int right=fruits[i][j]+solve2(i,j+1,fruits);
    int downd=fruits[i][j]+solve2(i+1,j+1,fruits);
    return t[i][j]=max(upd,max(right,downd));
}
    int maxCollectedFruits(vector<vector<int>>&fruits){
        int n=fruits.size();
        int moves=n-1;
        //for first child
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    ans+=fruits[i][j];
                }
            }
        }
        t=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        ans+=solve(0,n-1,fruits);
        moves=n-1;
        t=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        ans+=solve2(n-1,0,fruits);
        return ans;
    }
};