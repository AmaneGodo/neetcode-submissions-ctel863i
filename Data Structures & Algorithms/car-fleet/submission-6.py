class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = [[pos, speed] for pos, speed in zip(position, speed)]
        res = []

        for car in sorted(pair)[::-1]:
            time_to_goal = (target - car[0]) / car[1]

            if res and res[-1] >= time_to_goal:
                continue

            else:
                res.append(time_to_goal)

        return len(res)