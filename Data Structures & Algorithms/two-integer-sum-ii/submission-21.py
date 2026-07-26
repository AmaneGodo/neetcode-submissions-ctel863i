class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i = 0;
        j = len(numbers) - 1

        while i < j:
            sm = numbers[i] + numbers[j]

            if target > sm:
                i += 1

            elif target < sm:
                j -= 1

            else:
                return [i + 1, j + 1]

        return [-1, -1]