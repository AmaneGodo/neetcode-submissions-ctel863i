class Solution {
    std::unordered_map<int, vector<int>> preMap;
    std::unordered_set<int> visited;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int crs) {
        if (visited.count(crs)) {
            return false;
        }

        if (preMap[crs].empty()) {
            return true;
        }

        visited.insert(crs);
        for (auto pre : preMap[crs]) {
            if (!dfs(pre)) {
                return false;
            }
        }

        visited.erase(crs);
        preMap[crs].clear();
        return true;
    }
};
