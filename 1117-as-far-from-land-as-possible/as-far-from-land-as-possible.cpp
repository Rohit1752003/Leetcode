/*
class Solution {
    private:
    int BFS(vector<vector<int>>& mat,
                            vector<vector<int>>& vis) {

        queue<pair<pair<int, int>, int>> q;

        int n = mat.size();
        int m = mat[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int land =0 , water =0;
        // Push all 0's into queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                    land++;

                } else {
                    vis[i][j] = 0;
                }
                if(mat[i][j]==0)water++;
            }
        }
        int maxDist = 0;
        while (!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            q.pop();

           maxDist = max(maxDist , steps);
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
        if(land== n*m || water == n*m)return -1;
        
        return maxDist;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {

         int n = grid.size();
        int m = grid[0].size();

        
        vector<vector<int>> vis(n, vector<int>(m, 0));

        return BFS(grid, vis);
    }
};
*/
class Solution {
    private:
    int BFS(vector<vector<int>>& mat,
                            vector<vector<int>>& vis) {

        queue<pair<pair<int, int>, int>> q;

        int n = mat.size();
        int m = mat[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int land =0 , water =0;
        // Push all 0's into queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                    land++;

                } else {
                    vis[i][j] = 0;
                }
                if(mat[i][j]==0)water++;
            }
        }
        int maxDist = 0;
        while (!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            q.pop();

           maxDist = max(maxDist , steps);
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
        if(land== n*m || water == n*m)return -1;
        
        return maxDist;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {

         int n = grid.size();
        int m = grid[0].size();

        
        vector<vector<int>> vis(n, vector<int>(m, 0));

        return BFS(grid, vis);
    }
};