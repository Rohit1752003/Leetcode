class Solution {
private:
    int BFS(vector<vector<int>>& grid,
            vector<vector<vector<int>>>& vis,
            int k) {

        int n = grid.size();
        int m = grid[0].size();

        if (n == 1 && m == 1) return 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        queue<vector<int>> q;
        q.push({0, 0, k, 0});   // row, col, remaining k, steps
        vis[0][0][k] = 1;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int row = curr[0];
            int col = curr[1];
            int rem = curr[2];
            int steps = curr[3];

            if (row == n - 1 && col == m - 1)
                return steps;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                    continue;

                // Empty cell
                if (grid[nrow][ncol] == 0 &&
                    !vis[nrow][ncol][rem]) {

                    vis[nrow][ncol][rem] = 1;
                    q.push({nrow, ncol, rem, steps + 1});
                }

                // Obstacle
                else if (grid[nrow][ncol] == 1 &&
                         rem > 0 &&
                         !vis[nrow][ncol][rem - 1]) {

                    vis[nrow][ncol][rem - 1] = 1;
                    q.push({nrow, ncol, rem - 1, steps + 1});
                }
            }
        }

        return -1;
    }

public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // Optimization
        if (k >= n + m - 2)
            return n + m - 2;

        vector<vector<vector<int>>> vis(
            n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        return BFS(grid, vis, k);
    }
};