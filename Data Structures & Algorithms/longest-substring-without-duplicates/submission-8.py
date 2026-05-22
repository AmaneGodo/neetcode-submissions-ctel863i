class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        res = 0
        count_set = set()

        for r in range(len(s)):
            while s[r] in count_set:
                count_set.remove(s[l])
                l += 1

            count_set.add(s[r])
            res = max(res, len(count_set))
        
        return res
