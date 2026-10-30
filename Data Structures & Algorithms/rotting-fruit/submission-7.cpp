class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }

    int bfs(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        int time = 0;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        std::queue<pair<int, int>> q;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    fresh++;
                }

                else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        while (!q.empty() && fresh > 0) {
            int level = q.size();

            for (int i = 0; i < level; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int next_row = row + directions[j][0];
                    int next_col = col + directions[j][1];

                    if (next_row >= 0 && next_row < rows &&
                        next_col >= 0 && next_col < cols &&
                        grid[next_row][next_col] == 1) {
                            grid[next_row][next_col] = 2;
                            fresh--;
                            q.push({next_row, next_col});
                        }
                }
            }

            time++;
        }

        if (fresh <= 0) {
            return time;
        } else {
            return -1;
        }
    }
};
