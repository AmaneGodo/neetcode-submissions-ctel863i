class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        res = [0] * len(temperatures)

        for i, temp in enumerate(temperatures):
            while stack and stack[-1][1] < temp:
                day, t = stack.pop()
                res[day] = i - day

            stack.append([i, temp])

        return res

                