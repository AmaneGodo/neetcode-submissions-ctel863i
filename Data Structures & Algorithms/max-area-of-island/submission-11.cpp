class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int area;
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                area = 0;
                if (grid[r][c] == 1) {
                    dfs(grid, r, c, area);
                    maxArea = std::max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

private:
    void dfs(vector<vector<int>>& grid, int r, int c, int& area) {
        int rows = grid.size();
        int cols = grid[0].size();
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        if (r < 0 ||
            r >= rows ||
            c < 0 ||
            c >= cols ||
            grid[r][c] == 0) {
                return;
            }

        grid[r][c] = 0;
        area++;
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + directions[i][0], c + directions[i][1], area);
        }

        return;
    }
};
