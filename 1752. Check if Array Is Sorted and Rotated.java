class Solution {
    public boolean check(int[] nums) {
        int n=nums.length;
        int cntTrue=0;

        for(int i=0; i<n; i++){
            cntTrue=0;
            for(int j=i+1; j<i+n; j++){
                if(nums[(j-1)%n]<=nums[j%n]){
                    cntTrue++;
                }
                else{
                    break;
                }
            }
            
            if(cntTrue+1==n){
                return true;
            }
        }

        return false;
    }
}