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
        

        if (r < 0 || r >= rows ||
            c < 0 || c >= cols ||
            grid[r][c] == 0) {
                return 0;
            }

        int res = 1;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        grid[r][c] = 0;
        for (int i = 0; i < 4; i++) {
            int next_r = r + directions[i][0];
            int next_c = c + directions[i][1];

            res += dfs(grid, next_r, next_c);
        }
        return res;
    }

    int bfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        std::queue<pair<int, int>> q;
        q.push({r, c});
        int res = 1;
        grid[r][c] = 0;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int next_r = row + directions[i][0];
                int next_c = col + directions[i][1];

                if (next_r >= 0 && next_r < rows &&
                    next_c >= 0 && next_c < cols &&
                    grid[next_r][next_c] == 1) {
                        grid[next_r][next_c] = 0;
                        q.push({next_r, next_c});
                        res++;
                    }
            }
        }

        return res;
    }

};
