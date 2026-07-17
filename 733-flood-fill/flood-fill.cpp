class Solution {
public:

    vector<vector<int>> Color(vector<vector<int>>& image,
                              int sr, int sc,
                              int color,
                              vector<vector<int>>& vis) {

        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> ans = image;

        if (image[sr][sc] == color)
            return ans;

        queue<pair<int, int>> q;

        vis[sr][sc] = 1;
        q.push({sr, sc});

        int st = image[sr][sc];
        ans[sr][sc] = color;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nrow = row + delRow[k];
                int ncol = col + delCol[k];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] &&
                    image[nrow][ncol] == st) {

                    vis[nrow][ncol] = 1;
                    ans[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }

        return ans;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int color) {

        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        return Color(image, sr, sc, color, vis);
    }
};