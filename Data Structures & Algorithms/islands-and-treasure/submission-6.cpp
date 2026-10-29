class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int next_r = r + directions[i][0];
                int next_c = c + directions[i][1];

                if (next_r >= 0 && next_r < rows &&
                    next_c >= 0 && next_c < cols &&
                    grid[next_r][next_c] == 2147483647) {
                        grid[next_r][next_c] = grid[r][c] + 1;
                        q.push({next_r, next_c});
                    }
            }
        }

        return;
    }
};
