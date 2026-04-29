class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, subset, 0, target, res);
        return res;
    }

private:
    void backtrack(const vector<int>& nums, vector<int>& subset, int i, int target, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if ((target < 0) || (i >= nums.size())) {
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums, subset, i, target - nums[i], res);
        subset.pop_back();
        backtrack(nums, subset, i + 1, target, res);
    }
};
