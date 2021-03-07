// 5698. Minimum Elements to Add to Form a Given Sum

class Solution {
    public int minElements(int[] nums, int limit, int goal) {
        long sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        long count = Math.abs((sum - goal) / limit);
        count += (sum - goal) % limit != 0 ? 1 : 0;
        return (int)count;
    }
}
