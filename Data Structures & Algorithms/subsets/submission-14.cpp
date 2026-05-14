class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, subset, 0, res);
        return res;
    }

private:
    void backtrack(const vector<int>& nums, vector<int>& subset, int i, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums, subset, i + 1, res);
        subset.pop_back();
        backtrack(nums, subset, i + 1, res);
    }
};
