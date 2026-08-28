class Solution {
public:
    bool solve(vector<vector<char>>& b, int r, int c,
               bool row[9][10], bool col[9][10], bool box[9][10]) {
        
        if (r == 9) return true;
        if (c == 9) return solve(b, r + 1, 0, row, col, box);
        if (b[r][c] != '.') return solve(b, r, c + 1, row, col, box);

        int k = (r / 3) * 3 + c / 3;

        for (int d = 1; d <= 9; d++) {
            if (!row[r][d] && !col[c][d] && !box[k][d]) {
                b[r][c] = '0' + d;
                row[r][d] = col[c][d] = box[k][d] = true;

                if (solve(b, r, c + 1, row, col, box))
                    return true;

                b[r][c] = '.';
                row[r][d] = col[c][d] = box[k][d] = false;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {}, col[9][10] = {}, box[9][10] = {};

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int d = board[i][j] - '0';
                    int k = (i / 3) * 3 + j / 3;
                    row[i][d] = col[j][d] = box[k][d] = true;
                }

        solve(board, 0, 0, row, col, box);
    }
};