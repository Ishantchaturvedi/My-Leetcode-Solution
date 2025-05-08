class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size(), m = moveTime[0].size();
            auto onGrid = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };
            
            int dx = 1, dy = 0;
            priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> heap;
            heap.emplace(0, 0, 0, 1);
    
            set<pair<int, int>> seen;
            seen.emplace(0, 0);
    
            while (!heap.empty()) {
                auto [time, x, y, step] = heap.top();
                heap.pop();
    
                if (x == n - 1 && y == m - 1) return time;
    
                for (int i = 0; i < 4; ++i) {
                    int X = x + dx, Y = y + dy;
                    int temp_dx = dx, temp_dy = dy;
                    dx = -temp_dy;
                    dy = temp_dx;
    
                    if (onGrid(X, Y) && !seen.count({X, Y})) {
                        int t = max(time, moveTime[X][Y]) + step;
                        heap.emplace(t, X, Y, 3 - step);
                        seen.emplace(X, Y);}
                }
            }
            return -1;
        }
    };