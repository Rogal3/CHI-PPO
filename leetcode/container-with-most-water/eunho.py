#https://leetcode.com/problems/container-with-most-water/submissions/
class Solution:
    def maxArea(self, height: List[int]) -> int:
        result=0
        left=0
        right=0
        for now_height in reversed(range(max(height)+1)):
            for i in range(len(height)):
                if height[i]>=now_height:
                    left=i
                    break
            for i in reversed(range(len(height))):
                if height[i]>=now_height:
                    right=i
                    break;
            if result <= now_height*(right-left):
                result=now_height*(right-left)
        return result
