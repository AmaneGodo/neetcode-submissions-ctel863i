class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l = 0;
        r = len(heights) - 1

        maxArea = 0

        while l < r:
            area = min(heights[l], heights[r]) * (r - l)
            maxArea = max(maxArea, area)

            if heights[l] <= heights[r]:
                l += 1

            elif heights[l] > heights[r]:
                r -= 1

        return maxArea