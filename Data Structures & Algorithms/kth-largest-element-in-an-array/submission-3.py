class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        hq = [-n for n in nums]
        heapq.heapify(hq)

        for i in range(k - 1):
            heapq.heappop(hq)

        return -hq[0]

        