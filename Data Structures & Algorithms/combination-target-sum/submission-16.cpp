class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, 0, cur, 0, target);
        return res;
    }

private:
    void dfs(const vector<int>& nums, vector<vector<int>>& res, int i, vector<int>& cur, int tot, int& target) {
        if (tot == target) {
            res.push_back(cur);
            return;
        }

        if (tot > target || i >= nums.size()) {
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, res, i, cur, tot + nums[i], target);
        cur.pop_back();
        dfs(nums, res, i + 1, cur, tot, target);
    }
};
