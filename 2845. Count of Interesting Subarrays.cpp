class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        #define int long long int 
        int cnt=0;
        for (int i =0;i<nums.size();i++){
            if (nums[i]% modulo == k){
                cnt++;
            }
            nums[i]=cnt;


        }

        map<int,int>mp;
        int ans =0;
        

        for (int i =0;i<nums.size();i++){
            int mod_val = nums[i]%modulo;
            
            if(mod_val==k) ans++;
            int rem = mod_val -k;
            
           

            if (rem<0) rem = rem + modulo;
            ans+=mp[rem];
            mp[mod_val]++;            
        }
        #undef int 

        return ans;
    }
};