class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        top = 0
        btm = len(matrix) - 1

        while btm > top:
            mid_row = (top + btm) // 2

            if matrix[mid_row][0] > target:
                btm = mid_row - 1

            elif matrix[mid_row][-1] < target:
                top = mid_row + 1

            else:
                break

        mid_row = (top + btm) // 2

        l = 0
        r = len(matrix[mid_row]) - 1

        while l <= r:
            mid = (l + r) // 2

            if matrix[mid_row][mid] == target:
                return True

            elif matrix[mid_row][mid] > target:
                r = mid - 1

            else:
                l = mid + 1

        return False