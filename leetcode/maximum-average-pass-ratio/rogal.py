# https://leetcode.com/problems/maximum-average-pass-ratio/

from queue import PriorityQueue

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        pq = PriorityQueue()
        for c in classes:
            pq.put((
                c[0] / c[1] - (c[0] + 1) / (c[1] + 1),
                c[0],
                c[1]
            ))
        while extraStudents:
            c = pq.get()
            pq.put((
                (c[1] + 1) / (c[2] + 1) - (c[1] + 2) / (c[2] + 2),
                c[1] + 1,
                c[2] + 1
            ))
            extraStudents -= 1
        sum_of_ratio = 0
        while not pq.empty():
            c = pq.get()
            sum_of_ratio += c[1] / c[2]
        return sum_of_ratio / len(classes)
