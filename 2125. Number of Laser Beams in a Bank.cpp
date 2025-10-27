class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long ans = 0;
        long long prev = 0;
        
        for (auto &row : bank) {
            long long cnt = 0;
            for (char ch : row) if (ch == '1') ++cnt;
            
            if (cnt > 0) {
                ans += prev * cnt;
                prev = cnt;
            }
        }
        return (int)ans;
    }
};