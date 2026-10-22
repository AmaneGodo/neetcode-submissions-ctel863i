class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    int area = bfs(grid, r, c, 1);
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

    int bfs(vector<vector<int>>& grid, int r, int c, int area) {
        int rows = grid.size();
        int cols = grid[0].size();
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        std::queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nxt_r = row + directions[i][0];
                int nxt_c = col + directions[i][1];

                if (nxt_r >= 0 &&
                    nxt_r < rows &&
                    nxt_c >= 0 &&
                    nxt_c < cols &&
                    grid[nxt_r][nxt_c] == 1) {
                        grid[nxt_r][nxt_c] = 0;
                        area++;
                        q.push({nxt_r, nxt_c});
                    }
            }
        }

        return area;
    }
};
