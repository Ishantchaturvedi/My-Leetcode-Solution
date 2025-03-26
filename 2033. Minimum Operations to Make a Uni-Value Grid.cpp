class Solution {
    public:
        int minOperations(std::vector<std::vector<int>>& grid, int x) {
            int rem = grid[0][0] % x;
            int m = grid.size();
            int n = grid[0].size();
            int i = 0;
            int no = m * n;
            std::vector<int> arr(no);
            
            for (const auto& row : grid) {
                for (int num : row) {
                    if (num % x != rem) return -1;
                    arr[i++] = num;
                }
            }
    
            std::sort(arr.begin(), arr.end());
            int mid = arr[no / 2];
            int ans = 0;
    
            for (int num : arr) {
                ans += std::abs(num - mid) / x;
            }
    
            return ans;
        }
    };