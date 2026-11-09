class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        mp = []
        res = []

        for x, y in points:
            dist = ((x) ** 2 + (y) ** 2) ** (1/2)
            mp.append([dist, x, y])

        heapq.heapify(mp)

        for i in range(k):
            dist, x, y = heapq.heappop(mp)
            res.append([x, y])

        return res
