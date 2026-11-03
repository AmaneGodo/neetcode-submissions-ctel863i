class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') {
                dfs(board, r, 0);
            } 
            
            if (board[r][cols - 1] == 'O') {
                dfs(board, r, cols - 1);
            }
        }

        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O') {
                dfs(board, 0, c);
            } 
            
            if (board[rows - 1][c] == 'O') {
                dfs(board, rows - 1, c);
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
                
                else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            board[r][c] != 'O') {
                return;
            }

        board[r][c] = 'T';
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < 4; i++) {
            dfs(board, r + directions[i][0], c + directions[i][1]);
        }
    }
};
