class Solution {
public:
    int differenceOfSums(int n, int m)
    {
        //time complexity: O(n)
        //space complexity: O(1)
        
        int i;
        int num1=0;
        int num2=0;

        for(i=1;i<=n;i++)
        {
            //if 'current-number' is not divisible by 'm', add it to 'num1'
            if(i%m!=0)
                num1=num1+i;
            //if 'current-number' is divisible by 'm', add it to 'num2'
            else
                num2=num2+i;
        }    
        //return the 'divisible and non-divisible sums difference'
        return num1-num2;
    }
};