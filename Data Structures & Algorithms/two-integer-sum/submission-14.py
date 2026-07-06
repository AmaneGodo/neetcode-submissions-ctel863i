class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        
        for i, n in enumerate(nums):
            need = target - n

            if need in mp:
                return [mp[need], i]

            mp[n] = i