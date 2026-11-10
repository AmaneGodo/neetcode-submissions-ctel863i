class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.hq = nums
        self.k = k

        heapq.heapify(self.hq)

        while len(self.hq) > self.k:
            heapq.heappop(self.hq)

    def add(self, val: int) -> int:
        heapq.heappush(self.hq, val)

        if len(self.hq) > self.k:
            heapq.heappop(self.hq)

        return self.hq[0]
