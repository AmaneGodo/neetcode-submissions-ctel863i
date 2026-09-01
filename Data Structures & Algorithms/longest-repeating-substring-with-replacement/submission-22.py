class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        max_len = 0
        count = {}
        l = 0
        max_char = 0

        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)
            max_char = max(max_char, count[s[r]])

            if (r - l + 1) - max_char > k:
                count[s[l]] -= 1
                l += 1
            
            max_len = max((r - l + 1), max_len)

        return max_len