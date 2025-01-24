class Solution {
    private:
    bool dfs(int node ,vector<int> &vis,vector<int> &pathvis,vector<vector<int>>& prerequisites,vector<int>&ans){
        vis[node]=1;
        pathvis[node]=1 ; 
        ans[node] = 0;

        for(auto it : prerequisites[node]){
            if(!vis[it]){
                // pathvis[it]=1 ;
                if(dfs(it,vis,pathvis,prerequisites,ans)==true){
                ans[node]=0;
                return true;
                }
            }
            else if(pathvis[it]){
                ans[node]=0;
                return true ; 
            }

        }
        ans[node]=1 ; 
        pathvis[node]= 0 ;
        return false ;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        vector<int>ans(V,0);
        vector<int>check;
        

        for(int i =0 ;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,graph,ans);
            }
        }
        for(int i =0 ; i<V;i++){
            if(ans[i]==1){
                 check.push_back(i);
            }       
        }
    return check;
    }
};