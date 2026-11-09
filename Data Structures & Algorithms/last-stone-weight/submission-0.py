class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        hq = [-s for s in stones]
        heapq.heapify(hq)

        while len(hq) > 1:
            first = heapq.heappop(hq)
            second = heapq.heappop(hq)

            if second > first:
                heapq.heappush(hq, first - second)

        if not hq:
            return 0

        else:
            return hq[0] * -1
