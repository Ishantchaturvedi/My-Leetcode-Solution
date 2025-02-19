class Solution {
    public:
        string res = "";
        int n, k;
        bool helper(int i, int prev){
            if(i == n) return --k == 0;
            for(char c = 'a'; c < 'd'; c++){
                if(c == prev) continue;
                if(helper(i + 1, c)){
                    res = c + res;
                    return true;
                }
            }
            return false;
        }
        string getHappyString(int n, int k) {
            this->n = n;
            this->k = k;
            helper(0, 'd');
            return res;
        }
    };