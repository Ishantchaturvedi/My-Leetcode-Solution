class Solution {
    public:
        void bfs(int i, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ne) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                ne[0]++;
    
                for (int num : adj[curr]) {
                    ne[1]++;
                    if (!visited[num]) {
                        q.push(num);
                        visited[num] = true;
                    }
                }
            }
        }
    
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            for (auto& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            
            int ans = 0;
            vector<bool> visited(n, false);
            
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    vector<int> ne(2, 0);
                    bfs(i, adj, visited, ne);
                    if (ne[0] * (ne[0] - 1) / 2 == ne[1] / 2) {
                        ans++;
                    }
                }
            }
            return ans;
        }
    };