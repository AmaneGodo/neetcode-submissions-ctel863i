class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)

        res = 0

        while l <= r:
            k = (l + r) // 2

            time_to_eat = 0
            for p in piles:
                time_to_eat += math.ceil(float(p / k))

            if time_to_eat > h:
                l = k + 1

            else:
                res = k
                r = k - 1

        return res