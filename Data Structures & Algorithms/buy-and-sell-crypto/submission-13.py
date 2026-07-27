class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l = 0
        res = 0

        for r in range(1, len(prices), 1):
            if prices[r] - prices[l] > 0:
                res = max(res, prices[r] - prices[l])

            else:
                l = r

        return res
