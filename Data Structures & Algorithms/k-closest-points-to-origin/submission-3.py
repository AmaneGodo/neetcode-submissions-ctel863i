class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        dist_points_hq = []

        for x, y in points:
            dist = x ** 2 + y ** 2
            dist_points_hq.append([dist, [x, y]])

        heapq.heapify(dist_points_hq)
        output = []

        for i in range(k):
            dist, points = heapq.heappop(dist_points_hq)
            output.append(points)


        return output
