class Solution {
    int BFS(int i , int j , vector<vector<int>>& mat , vector<vector<int>> &vis){
         int n = mat.size();
        int m = mat[0].size();
        int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delCol[] = {-1,  0,  1, 1, 1, 0,-1,-1};
        if(mat[i][j] != 0 || mat[n-1][m-1] != 0)return -1;
           queue<pair<pair<int,int>,int>> q;
        q.push({{i,j},1});
        vis[i][j]=1;
      
        while(!q.empty()){
             int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;

            q.pop();
            if(row == n-1 && col == m-1)return steps;
            for(int i =0 ; i < 8 ; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]==0){
                    vis[nrow][ncol] =1;
                    q.push({{nrow,ncol},steps+1});
                    

                }
                
            }

        }
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
          int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        return BFS(0,0,grid,vis);
    }
};