class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        bfs(grid);
    }

    void bfs(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        std::queue<pair<int, int>> q;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int next_row = row + directions[i][0];
                int next_col = col + directions[i][1];

                if (next_row >= 0 && next_row < rows &&
                    next_col >= 0 && next_col < cols &&
                    grid[next_row][next_col] == 2147483647) {
                        grid[next_row][next_col] = grid[row][col] + 1;
                        q.push({next_row, next_col});
                    }
            }
        }

        return;
    }
};
