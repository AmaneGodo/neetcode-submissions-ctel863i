class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, target, 0, res, cur, 0);
        return res;

    }

private:
    void dfs(const vector<int>& candidates, int target, int tot, vector<vector<int>>& res, vector<int>& cur, int i) {
        if (tot == target) {
            res.push_back(cur);
            return;
        }

        if (tot > target || i >= candidates.size()) {
            return;
        }

        cur.push_back(candidates[i]);
        dfs(candidates, target, tot + candidates[i], res, cur, i + 1);
        cur.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        dfs(candidates, target, tot, res, cur, i + 1);
    }
};
