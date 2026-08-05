class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        top = 0
        btm = len(matrix) - 1

        while top <= btm:
            mid_row = (top + btm) // 2

            if matrix[mid_row][-1] < target:
                top = mid_row + 1

            elif matrix[mid_row][0] > target:
                btm = mid_row - 1

            else:
                break

        row = matrix[mid_row]

        l = 0
        r = len(row) - 1

        while l <= r:
            mid = (l + r) // 2

            if row[mid] == target:
                return True

            elif row[mid] < target:
                l = mid + 1

            else:
                r = mid - 1

        return False