class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        hq = []

        for x, y in points:
            dist = ((x) ** 2 + (y) ** 2) ** (1/2)

            hq.append([dist, x, y])

        heapq.heapify(hq)
        res = []

        for i in range(k):
            dist, x, y = heapq.heappop(hq)

            res.append([x, y])

        return res