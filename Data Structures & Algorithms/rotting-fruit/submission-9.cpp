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
        std::queue<pair<int, int>> q;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    fresh++;
                }

                if (grid[r][c] == 2) {
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
                int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int next_r = r + directions[j][0];
                    int next_c = c + directions[j][1];

                    if (next_r >= 0 && next_r < rows &&
                        next_c >= 0 && next_c < cols &&
                        grid[next_r][next_c] == 1) {
                            fresh--;
                            grid[next_r][next_c] = 2;
                            q.push({next_r, next_c});
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
