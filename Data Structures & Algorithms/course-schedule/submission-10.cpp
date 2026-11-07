class Solution {
public:
    std::unordered_map<int, vector<int>> mp;
    std::unordered_set<int> seen;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            mp[i] = {};
        }

        for (const auto& prereq : prerequisites) {
            mp[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int crs) {
        if (seen.count(crs)) {
            return false;
        }

        if (mp[crs].empty()) {
            return true;
        }

        seen.insert(crs);

        for (auto pre : mp[crs]) {
            if (!dfs(pre)) {
                return false;
            }
        }

        seen.erase(crs);
        mp[crs].clear();

        return true;
    }
};
