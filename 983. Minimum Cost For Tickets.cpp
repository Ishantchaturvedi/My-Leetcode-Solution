class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int max_days=*max_element(days.begin(),days.end());
        vector<int>dp(max_days+1,0);
        int day_ind=0;
        dp[0]=0;
       for(int i=1;i<=max_days;i++)
       {
            if(i==days[day_ind])
            {
                int thirty_day=INT_MAX,seven_day=INT_MAX,one_day=INT_MAX;
                
                one_day=costs[0]+dp[i-1];
    
                
                seven_day=costs[1]+(i>=7 ?dp[i-7]:0);
                
                
                thirty_day=costs[2]+(i>=30?dp[i-30]:0);
                

                dp[i]=min({thirty_day,seven_day,one_day});
                day_ind++;
            }
            else
            {
                dp[i]=dp[i-1];
            }
       }

       return dp[max_days];
    }
};