class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = set(nums)
        longest = 0
        length = 0

        for n in nums:
            if n - 1 not in seen:
                length = 0

                while n in seen:
                    length += 1
                    n += 1

            longest = max(longest, length)

        return longest