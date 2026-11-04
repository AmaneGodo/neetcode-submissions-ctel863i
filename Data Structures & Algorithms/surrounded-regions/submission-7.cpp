class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for (int r = 0; r < board.size(); r++) {
            if (board[r][0] == 'O') {
                dfs(board, r, 0);
            }

            if (board[r][board[0].size() - 1] == 'O') {
                dfs(board, r, board[0].size() - 1);
            }
        }

        for (int c = 0; c < board[0].size() - 1; c++) {
            if (board[0][c] == 'O') {
                dfs(board, 0, c);
            }

            if (board[board.size() - 1][c] == 'O') {
                dfs(board, board.size() - 1, c);
            }
        }

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                } else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }

        return;
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            board[r][c] != 'O') {
                return;
            }

        board[r][c] = 'T';
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < 4; i++) {
            int next_r = r + directions[i][0];
            int next_c = c + directions[i][1];

            dfs(board, next_r, next_c);
        }
    }

};
