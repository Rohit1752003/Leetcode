class Solution {
private:

    int BFS(vector<vector<int>>& grid, vector<vector<int>>& vis) {

        queue<pair<pair<int,int>,int>> q;

        int freshCnt = 0;
        int cnt = 0;
        int tm = 0;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(grid[i][j]==2){

                    vis[i][j]=1;
                    q.push({{i,j},0});

                }

                if(grid[i][j]==1)
                    freshCnt++;
            }
        }

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        while(!q.empty()){

            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;

            q.pop();

            tm=max(tm,time);

            for(int k=0;k<4;k++){

                int nrow=row+delRow[k];
                int ncol=col+delCol[k];

                if(nrow>=0 && nrow<n &&
                   ncol>=0 && ncol<m &&
                   !vis[nrow][ncol] &&
                   grid[nrow][ncol]==1){

                    vis[nrow][ncol]=1;
                    cnt++;

                    q.push({{nrow,ncol},time+1});

                }
            }
        }

        if(cnt!=freshCnt)
            return -1;

        return tm;
    }

public:

    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        return BFS(grid,vis);
    }
};