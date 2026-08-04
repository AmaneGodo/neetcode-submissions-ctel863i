class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, btm = matrix.size() - 1;
        int mid_row = 0;

        while (top <= btm) {
            mid_row = (top + btm) / 2;

            if (matrix[mid_row].back() < target) {
                top = mid_row + 1;
            }

            else if (matrix[mid_row].front() > target) {
                btm = mid_row - 1;
            }

            else {
                break;
            }
        }

        vector<int> row = matrix[mid_row];

        int l = 0, r = row.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (row[mid] == target) {
                return true;
            }

            else if (row[mid] > target) {
                r = mid - 1;
            }

            else {
                l = mid + 1;
            }
        }

        return false;
    }
};
