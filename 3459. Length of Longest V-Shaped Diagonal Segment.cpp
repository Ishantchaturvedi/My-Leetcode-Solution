class Solution {
public:
    int m,n;
    vector<vector<int>> dir = {
        {-1,-1},
        {-1,1},
        {1,1},
        {1,-1}
    };
    int dp[501][501][4][2];

    int f(vector<vector<int>>& grid, int i,int j,int k,int turn,bool t){
        if(i<0 || i>=n || j<0 || j>=m)
            return 0;
        if(dp[i][j][k][turn]!=-1)
            return dp[i][j][k][turn];
        int val=(t)?0:2;
        if(grid[i][j]!=val)
            return 0;
        int ni=i+dir[k][0];
        int nj=j+dir[k][1];
        int p1=f(grid,ni,nj,k,turn,!t);
        int p2=0;
        if(turn<1){
            int nk=(k+1)%4;
            int ni2=i+dir[nk][0],nj2=j+dir[nk][1];
            p2=f(grid,ni2,nj2,nk,turn+1,!t);
        }
        return dp[i][j][k][turn]=1+max(p1,p2);
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int res=0;
        n=grid.size(),m=grid[0].size();

        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++)
                        res=max(res,1+f(grid,i+dir[k][0],j+dir[k][1],k,0,0));
                }
            }
        }
        return res;
    }
};