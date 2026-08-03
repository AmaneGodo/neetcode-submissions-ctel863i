class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        each_count = defaultdict(int)
        l = 0
        res = 0

        for r in range(len(s)):
            each_count[s[r]] += 1

            if each_count and (r - l + 1) - max(each_count.values()) > k:
                each_count[s[l]] -= 1
                l += 1

            res = max(res, r - l + 1)

        return res
