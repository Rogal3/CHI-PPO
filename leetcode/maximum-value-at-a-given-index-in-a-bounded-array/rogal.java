// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/submissions/

class Solution {
    public int maxValue(int n, int index, int maxSum) {
        int l = 0, r = maxSum + 1;
        while (l < r) {
            int m = (l + r) / 2;
            System.out.println(String.format("l = %d, r = %d, sum = %d", l, r, getSum(m, n, index)));
            if (getSum(m, n, index) <= (long)maxSum) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        // System.out.println();
        return l - 1;
    }

    public long getSum(int h, int n, int index) {
        long sum = (long)h * h;
        if (index - (h - 1) > 0) {
            int d = index - (h - 1);
            sum += d;
        }
        if (index - (h - 1) < 0) {
            int d = h - index - 1;
            sum -= (long)d * (d + 1) / 2;
        }
        if (index + (h - 1) < n - 1) {
            int d = (n - 1) - (index + h - 1);
            sum += d;
        }
        if (index + (h - 1) > n - 1) {
            int d = index + h - 1 - (n - 1);
            sum -= (long)d * (d + 1) / 2;
        }
        return sum;
    }
}
