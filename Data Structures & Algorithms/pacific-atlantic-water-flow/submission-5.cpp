class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       int rows = heights.size();
       int cols = heights[0].size();
       std::set<pair<int, int>> pac;
       std::set<pair<int, int>> atl;
       vector<vector<int>> res;

        for (int r = 0; r < rows; r++) {
           dfs(heights, pac, r, 0, 0);
           dfs(heights, atl, r, cols - 1, 0); 
        }

        for (int c = 0; c < cols; c++) {
            dfs(heights, pac, 0, c, 0);
            dfs(heights, atl, rows - 1, c, 0);
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pac.count({r, c}) && atl.count({r, c})) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& heights, std::set<pair<int, int>>& visited, int r, int c, int prev_height) {
        if (r < 0 || r >= heights.size() ||
            c < 0 || c >= heights[0].size() ||
            visited.count({r, c}) ||
            heights[r][c] < prev_height) {
                return;
            }

        visited.insert({r, c});
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < 4; i++) {
            int next_r = r + directions[i][0];
            int next_c = c + directions[i][1];

            dfs(heights, visited, next_r, next_c, heights[r][c]);
        }
    }
};
