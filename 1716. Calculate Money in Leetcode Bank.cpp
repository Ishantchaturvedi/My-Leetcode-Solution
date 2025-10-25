class Solution {
public:
    int totalMoney(int n) {
        int first=1;
        int second=first+1;
        int sum=0;
        int cnt=1;
        while(cnt<=n){
           if(cnt%7==1){
              sum+=first;
              first++;
              second=first;
           }
           else{
             sum+=second;
             second++;
           }
           cnt++;
        }
        return sum;
    }
};