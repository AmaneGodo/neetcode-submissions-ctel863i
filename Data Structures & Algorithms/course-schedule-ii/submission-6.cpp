class Solution {
public:
    std::unordered_map<int, vector<int>> mp;
    std::unordered_set<int> taken;
    std::unordered_set<int> cycle;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;

        for (int i = 0; i < numCourses; i++) {
            mp[i] = {};
        }

        for (const auto pre : prerequisites) {
            mp[pre[0]].push_back(pre[1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c, res)) {
                return {};
            } 
        }

        return res;
    }

    bool dfs(int crs, vector<int>& res) {
        if (cycle.count(crs)) {
            return false;
        }

        if (taken.count(crs)) {
            return true;
        }

        cycle.insert(crs);

        for (int pre : mp[crs]) {
            if (!dfs(pre, res)) {
                return false;
            }
        }

        cycle.erase(crs);
        taken.insert(crs);
        mp[crs].clear();
        res.push_back(crs);
        return true;
    }
};
