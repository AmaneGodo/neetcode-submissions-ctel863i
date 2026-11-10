class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        hq = nums
        heapq.heapify(hq)

        while len(hq) > k:
            heapq.heappop(hq)

        return hq[0]