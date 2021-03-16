// https://leetcode.com/problems/container-with-most-water

class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxOfLeft = height[left];
        int maxOfRight = height[right];
        int max = 0;
        while (left < right) {
            max = Math.max(max, Math.min(maxOfLeft, maxOfRight) * (right - left));
            if (maxOfLeft < maxOfRight) {
                left++;
                maxOfLeft = Math.max(maxOfLeft, height[left]);
            } else {
                right--;
                maxOfRight = Math.max(maxOfRight, height[right]);
            }
        }
        return max;
    }
}
