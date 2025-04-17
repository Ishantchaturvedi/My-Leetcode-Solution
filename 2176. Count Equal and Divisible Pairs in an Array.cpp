class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            unordered_map<int, vector<int>> pos;  
            int count = 0;
            
            for (int i = 0; i < nums.size(); ++i) {
                
                for (int j : pos[nums[i]]) {
                    if ((i * j) % k == 0) {
                        count++;
                    }
                }
                
                pos[nums[i]].push_back(i);
            }
            
            return count;
        }
    };