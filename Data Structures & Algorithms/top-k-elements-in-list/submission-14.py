class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}

        for n in nums:
            count[n] = 1 + count.get(n, 0)

        frq = [[] for i in range(len(nums) + 1)]

        for n, cnt in count.items():
            frq[cnt].append(n)

        res = []

        for i in range(len(frq) - 1, -1, -1):
            for n in frq[i]:
                if n not in frq[i]:
                    continue

                else:
                    res.append(n)

                    if len(res) == k:
                        return res
        