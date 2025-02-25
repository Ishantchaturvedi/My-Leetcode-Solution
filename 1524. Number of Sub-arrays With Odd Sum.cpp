class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) 
        {
            int MOD = pow(10,9)+7;
            int ans = 0;
            int odd = 0;
            int even = 0;
            int vk = 0;
            for (int num:arr)
            {
                vk += num;
                vk%=2;
                if (vk==1)
                {
                    odd++;
                    ans += 1+even;
                }
                else
                {
                    even++;
                    ans += odd;
                }
                ans%=MOD;
            }
            return ans;
        }
    };