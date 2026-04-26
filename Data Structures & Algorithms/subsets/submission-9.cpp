class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, subset, 0, res);
        return res;
    }

private:
    void dfs(const vector<int>& nums, vector<int>& subset, int i, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, subset, i + 1, res);
        subset.pop_back();
        dfs(nums, subset, i + 1, res);
    }
};
