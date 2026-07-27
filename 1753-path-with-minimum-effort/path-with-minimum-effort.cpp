class Solution {
     int BFS(int i , int j , vector<vector<int>>& mat , vector<vector<int>> &effort){
      int n = mat.size();
        int m = mat[0].size();
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});
         int delRow[] = {-1,0,1,0};
         int delCol[] = {0,1,0,-1};
      
        
      
        while(!pq.empty()){
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            int Curreffort=pq.top().first;

            pq.pop();
            if(row == n-1 && col ==m-1)return Curreffort;
            if(Curreffort > effort[row][col])continue;
            for(int i =0 ; i < 4 ; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                int newEffort = max(Curreffort, abs(mat[row][col] - mat[nrow][ncol]));                
                if(newEffort < effort[nrow][ncol]){
                   effort[nrow][ncol] =  newEffort;
                    pq.push({newEffort,{nrow,ncol}});
                }
                }

                
            
            }

        }
        return -1;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        return BFS(0,0,heights,effort);
    }
};