/**
 * https://programmers.co.kr/learn/courses/30/lessons/42889
 */

import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] distribution = new int[N + 2]; // [1, N + 1]
        for (int i = 0; i < stages.length; i++) {
            distribution[stages[i]]++;
        }
        int[] cumSum = new int[N + 3]; // [1, N + 2]
        for (int i = distribution.length - 1; 0 < i; i--) {
            cumSum[i] = cumSum[i + 1] + distribution[i];
        }
        class Stage {
            int num;
            int stay;
            int pass;
            Stage(int num, int stay, int pass) {
                this.num = num;
                this.stay = stay;
                this.pass = pass;
            }
        }
        List<Stage> list = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            // System.out.println(String.format("%4d %4d %4d", i, distribution[i], cumSum[i]));
            list.add(new Stage(i, distribution[i], cumSum[i]));
        }
        return list.stream()
                .sorted((o2, o1) -> Long.compare((long)o1.stay * o2.pass, (long)o2.stay * o1.pass))
                .mapToInt(o -> o.num)
                .toArray();
    }
}
