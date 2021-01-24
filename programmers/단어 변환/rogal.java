/**
 * https://programmers.co.kr/learn/courses/30/lessons/43163
 * 단어 변환
 */

import java.util.*;
import java.util.stream.Stream;

class Solution {
    public int solution(String begin, String target, String[] words) {
        words = Stream.concat(Stream.of(words), Stream.of(begin)).toArray(String[]::new);
        int indexOfBegin = words.length - 1, indexOfTarget = -1;
        for (int i = 0; i < words.length; i++) {
            // System.out.println(words[i].equals(target));
            if (words[i].equals(target)) indexOfTarget = i;
        }
        if (indexOfTarget == -1) return 0;
        boolean[][] graph = getGraph(words);
        return bfs(indexOfBegin, indexOfTarget, graph);
    }

    public boolean[][] getGraph(String[] words) {
        boolean[][] graph = new boolean[words.length][words.length];
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words.length; j++) {
                int countOfMismatch = 0;
                for (int k = 0; k < words[0].length(); k++) {
                    if (words[i].charAt(k) != words[j].charAt(k)) {
                        countOfMismatch++;
                        if (countOfMismatch == 2) {
                            break;
                        }
                    }
                }
                if (countOfMismatch == 1) {
                    // System.out.println(String.format("%s %s", words[i], words[j]));
                    graph[i][j] = true;
                    graph[j][i] = true;
                }
            }
        }
        return graph;
    }

    public int bfs(int indexOfBegin, int indexOfTarget, boolean[][] graph) {
        int count = 0;
        boolean[] visited = new boolean[graph.length];
        Queue<Integer> q = new LinkedList<>();
        q.add(indexOfBegin);
        visited[indexOfBegin] = true;
        while (!q.isEmpty()) {
            for (int i = q.size(); 0 < i; i--) {
                int current = q.poll();
                if (current == indexOfTarget) return count;
                for (int j = 0; j < graph.length; j++) {
                    if (!visited[j] && graph[current][j]) {
                        q.add(j);
                        visited[j] = true;
                    }
                }
            }
            count++;
        }
        return 0;
    }
}
