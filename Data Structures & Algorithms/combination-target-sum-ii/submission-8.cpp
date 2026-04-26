class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        backtrack(candidates, target, 0, subset);
        return res;
    }

    void backtrack(const vector<int>& candidates, int target, int i, vector<int>& subset) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (i >= candidates.size() || 0 > target) {
            return;
        }

        subset.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i + 1, subset);
        subset.pop_back();
        while (candidates[i] == candidates[i + 1]) {
            i++;
        }
        backtrack(candidates, target, i + 1, subset);
    }
};
