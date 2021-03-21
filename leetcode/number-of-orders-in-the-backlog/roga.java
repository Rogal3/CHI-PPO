// https://leetcode.com/contest/weekly-contest-233/problems/number-of-orders-in-the-backlog/

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public int getNumberOfBacklogOrders(int[][] orders) {
        Queue<int[]> buyBacklog = new PriorityQueue<>((o2, o1) -> o1[0] - o2[0]);
        Queue<int[]> sellBacklog = new PriorityQueue<>((o1, o2) -> o1[0] - o2[0]);
        for (var order : orders) {
            if (order[2] == 0) {
                //buy
                while (!sellBacklog.isEmpty() && order[1] > 0 && sellBacklog.peek()[0] <= order[0]) {
                    int matches = Math.min(sellBacklog.peek()[1], order[1]);
                    sellBacklog.peek()[1] -= matches;
                    order[1] -= matches;
                    if (sellBacklog.peek()[1] == 0) {
                        sellBacklog.poll();
                    }
                }
                if (order[1] > 0) {
                    buyBacklog.offer(order);
                }
            } else {
                //sell
                while (!buyBacklog.isEmpty() && order[1] > 0 && buyBacklog.peek()[0] >= order[0]) {
                    int matches = Math.min(buyBacklog.peek()[1], order[1]);
                    buyBacklog.peek()[1] -= matches;
                    order[1] -= matches;
                    if (buyBacklog.peek()[1] == 0) {
                        buyBacklog.poll();
                    }
                }
                if (order[1] > 0) {
                    sellBacklog.offer(order);
                }
            }
        }
        long sum = 0;
        long moduler = 1000000007;
        while (!buyBacklog.isEmpty()) {
            sum = (sum + buyBacklog.poll()[1]) % moduler;
        }
        while (!sellBacklog.isEmpty()) {
            sum = (sum + sellBacklog.poll()[1]) % moduler;
        }
        return (int)sum;
    }
}
