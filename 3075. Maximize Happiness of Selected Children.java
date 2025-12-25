class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long sum = 0;
        int cnt = 0;

        for (int i = happiness.length - 1; i >= 0 && k > 0; i--) {
            int val = happiness[i] - cnt;
            if (val <= 0) break;
            sum += val;
            cnt++;
            k--;
        }
        return sum;
    }
}