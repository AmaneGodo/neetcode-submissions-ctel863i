class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        res = [0] * len(temperatures)

        for day, temp in enumerate(temperatures):
            while stack and temp > stack[-1][1]:
                d, t = stack.pop()
                res[d] = day - d

            stack.append([day, temp])

        return res