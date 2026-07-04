class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count_dict = {}
        l = 0
        res = 0

        for r in range(len(s)):

            count_dict[s[r]] = 1 + count_dict.get(s[r], 0)

            while (r - l + 1) - max(count_dict.values()) > k:
                count_dict[s[l]] -= 1
                l += 1

            res = max(res, r - l + 1)

        return max(res, r - l + 1)
    