class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int a = 0;

        for (int i = 0; i <= r - 3; i++) {
            for (int j = 0; j <= c - 3; j++) {

                // center must be 5
                if (grid[i+1][j+1] != 5) continue;

                vector<int> freq(10, 0);
                bool valid = true;

                // check 1–9 and distinct
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        int val = grid[x][y];
                        if (val < 1 || val > 9 || freq[val]++) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) break;
                }

                if (!valid) continue;

                int s = grid[i][j] + grid[i][j+1] + grid[i][j+2];

                // check rows, columns, diagonals
                if (
                    grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] != s ||
                    grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] != s ||
                    grid[i][j] + grid[i+1][j] + grid[i+2][j] != s ||
                    grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] != s ||
                    grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] != s ||
                    grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != s ||
                    grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != s
                ) continue;

                // finally valid magic square
                a++;
            }
        }
        return a;
    }
};
