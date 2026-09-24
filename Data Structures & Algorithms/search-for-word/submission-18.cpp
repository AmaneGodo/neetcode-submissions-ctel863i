class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        std::set<pair<int, int>> visited;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, visited, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(const auto& board, string word, set<pair<int, int>>& visited, int r, int c, int i) {
        int rows = board.size();
        int cols = board[0].size();

        if (i >= word.length()) {
            return true;
        }

        if  (r < 0 ||
             c < 0 ||
             r >= rows ||
             c >= cols ||
             board[r][c] != word[i] ||
             visited.find({r, c}) != visited.end()) {
                return false;
             }

        visited.insert({r, c});
        bool res = (dfs(board, word, visited, r + 1, c, i + 1) ||
                    dfs(board, word, visited, r - 1, c, i + 1) ||
                    dfs(board, word, visited, r, c + 1, i + 1) ||
                    dfs(board, word, visited, r, c - 1, i + 1));

        visited.erase({r, c});

        return res;
    }
};
