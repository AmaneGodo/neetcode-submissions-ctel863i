class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = [[pos, speed] for pos, speed in zip(position, speed)]
        fleets = []

        for car in sorted(pair)[::-1]:
            time = (target - car[0]) / car[1]

            if fleets and time <= fleets[-1]:
                continue

            else:
                fleets.append(time)

        return len(fleets)