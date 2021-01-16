/**
 * https://programmers.co.kr/learn/courses/30/lessons/42627
 */

import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        Arrays.sort(jobs, (o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : o1[0] - o2[0]);
        PriorityQueue<int[]> heap = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
        int t = 0;
        int answer = 0;
        for (int[] job : jobs) {
            while (!heap.isEmpty() && t < job[0]) {
                System.out.print("begin : " + t + ", [" + heap.peek()[0] + " " + heap.peek()[1] + "] ");
                t += heap.peek()[1];
                System.out.println(", delay : " + (t - heap.peek()[0]));
                answer += t - heap.poll()[0];
            }
            if (heap.isEmpty() && t < job[0]) {
                System.out.print("begin : " + job[0] + ", [" + job[0] + " " + job[1] + "]");
                t = job[0] + job[1];
                answer += job[1];
                System.out.println(", delay : " + job[1]);
            } else {
                heap.add(job);
            }
        }
        while (!heap.isEmpty()) {
            System.out.print("begin : " + t + ", [" + heap.peek()[0] + " " + heap.peek()[1] + "] ");
            t += heap.peek()[1];
            System.out.println(", delay : " + (t - heap.peek()[0]));
            answer += t - heap.poll()[0];
        }
        return answer / jobs.length;
    }
}
