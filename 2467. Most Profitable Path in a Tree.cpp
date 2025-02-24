class Solution {
    private:
        vector<vector<int>> graph;
        vector<int> bobPath;
        vector<int> parent;
        
        // Find Bob's path to root (node 0)
        bool findBobPath(int node, int par, vector<int>& path) {
            path.push_back(node);
            if (node == 0) return true;
            
            for (int next : graph[node]) {
                if (next != par) {
                    if (findBobPath(next, node, path)) return true;
                }
            }
            path.pop_back();
            return false;
        }
        
        // DFS to find Alice's maximum possible income
        int dfs(int node, int par, int depth, vector<int>& amount, unordered_map<int, int>& bobDist) {
            int maxIncome = INT_MIN;
            bool isLeaf = true;
            
            // Calculate current node's contribution
            int currentAmount = 0;
            if (!bobDist.count(node)) {
                // Bob never reaches this node
                currentAmount = amount[node];
            } else if (depth == bobDist[node]) {
                // Alice and Bob reach simultaneously
                currentAmount = amount[node] / 2;
            } else if (depth < bobDist[node]) {
                // Alice reaches before Bob
                currentAmount = amount[node];
            }
            
            // Explore all children
            for (int next : graph[node]) {
                if (next != par) {
                    isLeaf = false;
                    maxIncome = max(maxIncome, 
                        dfs(next, node, depth + 1, amount, bobDist));
                }
            }
            
            // If it's a leaf node, return just the current amount
            if (isLeaf) return currentAmount;
            
            // Otherwise, return current amount plus max from children
            return currentAmount + maxIncome;
        }
        
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size();
            
            // Build adjacency list
            graph.resize(n);
            for (const auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            
            // Find Bob's path to root
            vector<int> bobPathVec;
            findBobPath(bob, -1, bobPathVec);
            
            // Create map of Bob's distances to each node
            unordered_map<int, int> bobDist;
            for (int i = 0; i < bobPathVec.size(); i++) {
                bobDist[bobPathVec[i]] = i;
            }
            
            // Find Alice's maximum income starting from root
            return dfs(0, -1, 0, amount, bobDist);
        }
    };