class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        int sm;

        while (i < j) {
            sm = numbers[i] + numbers[j];

            if (target > sm) {
                i++;
            }
            else if (target < sm) {
                j--;
            }
            else {
                return {i + 1, j + 1};
            }
        }

        return {-1, -1};
        
    }
};
