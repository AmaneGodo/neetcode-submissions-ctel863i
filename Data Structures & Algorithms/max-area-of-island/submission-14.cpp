class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    maxArea = std::max(maxArea, bfs(grid, r, c));
                }
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        if (r < 0 || r >= rows ||
            c < 0 || c >= cols ||
            grid[r][c] == 0) {
                return 0;
            }

        grid[r][c] = 0;
        int res = 1;
        for (int i = 0; i < 4; i++) {
            res += dfs(grid, r + directions[i][0], c + directions[i][1]);
        }

        return res;
    }

    int bfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        grid[r][c] = 0;
        int area = 1;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        std::queue<pair<int, int>> q;
        q.push({r, c});

        while (!q.empty()) {
            int this_row = q.front().first;
            int this_col = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int next_row = this_row + directions[i][0];
                int next_col = this_col + directions[i][1];

                if (next_row >= 0 && next_row < rows &&
                    next_col >= 0 && next_col < cols &&
                    grid[next_row][next_col] == 1) {
                        grid[next_row][next_col] = 0;
                        area++;
                        q.push({next_row, next_col});
                    }
            }
        }

        return area;

    }
};
