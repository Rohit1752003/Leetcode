class Solution {
    int solve(int i, int j,
              vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        if (j < 0 || j >= m)
            return 1e9;

        if (i == n - 1)
            return dp[i][j] =  grid[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int down =
            grid[i][j] +
            solve(i + 1, j, grid, dp);

        int rightDiag =
            grid[i][j] +
            solve(i + 1, j + 1, grid, dp);

        int leftDiag =
            grid[i][j] +
            solve(i + 1, j - 1, grid, dp);

        return dp[i][j] =
            min(down, min(leftDiag, rightDiag));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(
            n, vector<int>(m, INT_MAX));

        int ans = 1e9;

        for (int j = 0; j < m; j++) {
            ans = min(ans,
                      solve(0, j, matrix, dp));
        }

        return ans;
    }
};