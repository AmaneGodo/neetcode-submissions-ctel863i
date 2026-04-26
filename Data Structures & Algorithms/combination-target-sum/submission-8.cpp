class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        backtrack(nums, target, 0, subset);
        return res;
    }

    void backtrack(const vector<int>& nums, int target, int i, vector<int>& subset) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (i >= nums.size() || 0 > target) {
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums, target - nums[i], i, subset);
        subset.pop_back();
        backtrack(nums, target, i + 1, subset);
    }
};
