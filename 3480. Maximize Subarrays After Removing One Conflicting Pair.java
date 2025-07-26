import java.util.*;

class Solution {
    public long maxSubarrays(int n, int[][] c) {
        int[] minB = new int[n + 1];
        int[] secondMinB = new int[n + 1];

        Arrays.fill(minB, Integer.MAX_VALUE);
        Arrays.fill(secondMinB, Integer.MAX_VALUE);

        for (int[] pair : c) {
            int a = Math.min(pair[0], pair[1]);
            int b = Math.max(pair[0], pair[1]);
            if (minB[a] > b) {
                secondMinB[a] = minB[a];
                minB[a] = b;
            } else if (secondMinB[a] > b) {
                secondMinB[a] = b;
            }
        }

        long total = 0;
        int bestMinIndex = n;
        int currentSecondMin = Integer.MAX_VALUE;
        long[] gainByRemoval = new long[n + 1];

        for (int i = n; i >= 1; i--) {
            if (minB[bestMinIndex] > minB[i]) {
                currentSecondMin = Math.min(currentSecondMin, minB[bestMinIndex]);
                bestMinIndex = i;
            } else {
                currentSecondMin = Math.min(currentSecondMin, minB[i]);
            }

            total += Math.min(minB[bestMinIndex], n + 1) - i;
            gainByRemoval[bestMinIndex] += Math.min(Math.min(currentSecondMin, secondMinB[bestMinIndex]), n + 1)
                                         - Math.min(minB[bestMinIndex], n + 1);
        }

        long maxGain = 0;
        for (long val : gainByRemoval) {
            maxGain = Math.max(maxGain, val);
        }

        return total + maxGain;
    }
}