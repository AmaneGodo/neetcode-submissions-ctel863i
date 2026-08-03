class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        ps = []
        for i in range(len(position)):
            ps.append([position[i], speed[i]])

        ps.sort()

        stack = []

        for i in range(len(ps) - 1, -1, -1):
            time = (target - ps[i][0]) / ps[i][1]

            if stack and stack[-1] >= time:
                continue

            stack.append(time)

        return len(stack)

