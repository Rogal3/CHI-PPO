// https://leetcode.com/contest/biweekly-contest-48/problems/maximum-number-of-consecutive-values-you-can-make/

import java.util.Arrays;

class Solution {
    public int getMaximumConsecutive(int[] coins) {
        Arrays.sort(coins);
        int[] cumulativeSum = new int[coins.length + 1];
        for (int i = 0; i < coins.length; i++) {
            cumulativeSum[i + 1] = cumulativeSum[i] + coins[i];
            if (cumulativeSum[i] < coins[i] - 1) {
                return cumulativeSum[i] + 1;
            }
        }
        return cumulativeSum[cumulativeSum.length - 1] + 1;
    }
}
