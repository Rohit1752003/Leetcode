class Solution {
private:
    vector<vector<int>> BFS(vector<vector<int>>& mat,
                            vector<vector<int>>& vis,
                            vector<vector<int>>& ans) {

        queue<pair<pair<int, int>, int>> q;

        int n = mat.size();
        int m = mat[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Push all 0's into queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            q.pop();

            ans[row][col] = steps;

            for (int i = 0; i < 4; i++) {

                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol]) {

                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }

        return ans;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        return BFS(mat, vis, ans);
    }
};