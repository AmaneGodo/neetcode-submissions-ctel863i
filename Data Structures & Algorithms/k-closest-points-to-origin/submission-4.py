class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        dp_hq = []

        for x, y in points:
            dist = x ** 2 + y ** 2

            dp_hq.append([dist, x, y])

        heapq.heapify(dp_hq)

        res = []
        for i in range(k):
            dist, x, y = heapq.heappop(dp_hq)
            res.append([x, y])

        return res