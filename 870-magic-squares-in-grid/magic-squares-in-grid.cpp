class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        // center must be 5
        if (g[r+1][c+1] != 5) return false;

        vector<int> cnt(10, 0);

        // check numbers 1 to 9, distinct
        for (int i = r; i < r+3; i++) {
            for (int j = c; j < c+3; j++) {
                int val = g[i][j];
                if (val < 1 || val > 9 || cnt[val]++) {
                    return false;
                }
            }
        }

        // check rows
        for (int i = 0; i < 3; i++) {
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != 15)
                return false;
        }

        // check columns
        for (int j = 0; j < 3; j++) {
            if (g[r][c+j] + g[r+1][c+j] + g[r+2][c+j] != 15)
                return false;
        }

        // check diagonals
        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != 15)
            return false;

        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != 15)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        if (n < 3 || m < 3) return 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }

        return count;
    }
};
