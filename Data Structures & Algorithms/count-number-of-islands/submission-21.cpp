class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c);
                    res++;
                }
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        constexpr int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        if (r < 0 ||
            r >= rows ||
            c < 0 ||
            c >= cols ||
            grid[r][c] == '0'
            ) {
                return; 
                }

        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + directions[i][0], c + directions[i][1]);
        }
    };

    void bfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        constexpr int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        std::queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] == '0';

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
                    grid[nxt_r][nxt_c] == '1') {
                        q.push({nxt_r, nxt_c});
                        grid[nxt_r][nxt_c] = '0';
                    }
            }
        }
    }
};
