class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, cur, 0, target, res);
        return res;

    }

private:
    void dfs(const vector<int>& candidates, int i, vector<int>& cur, int tot, int target, vector<vector<int>>& res) {
        if (tot == target) {
            res.push_back(cur);
            return;
        }

        if (tot > target || i >= candidates.size()) {
            return;
        }

        cur.push_back(candidates[i]);
        dfs(candidates, i + 1, cur, tot + candidates[i], target, res);
        cur.pop_back();
        while ((i + 1) < candidates.size() && candidates[i + 1] == candidates[i]) {
            i++;
        }
        dfs(candidates, i + 1, cur, tot, target, res);
    }
};
