class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, subset, 0, target, res);
        return res;
    }

private:
    void backtrack(const vector<int>& candidates, vector<int>& subset, int i, int target, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (target < 0 || i >= candidates.size()) {
            return;
        }

        subset.push_back(candidates[i]);
        backtrack(candidates, subset, i + 1, target - candidates[i], res);
        subset.pop_back();
        while (candidates[i] == candidates[i + 1]) {
            i++;
        }
        backtrack(candidates, subset, i + 1, target, res);
    }
};
