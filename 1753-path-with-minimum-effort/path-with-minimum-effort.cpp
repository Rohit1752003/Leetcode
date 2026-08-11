class Solution {
     int BFS(int i , int j , vector<vector<int>>& mat , vector<vector<int>> &dist){
      int n = mat.size();
        int m = mat[0].size();
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});
         int delRow[] = {-1,0,1,0};
         int delCol[] = {0,1,0,-1};
        while(!pq.empty()){
            int currDiff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(currDiff > dist[row][col])continue;
            if(row  == n-1 && col == m-1)return currDiff;
            for(int i =0 ; i< 4 ; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
              if(nrow < 0 || nrow >= n ||
                        ncol < 0 || ncol >= m)
                            continue;
                int newDiff = max(currDiff , abs(mat[row][col] - mat[nrow][ncol]));

                if(newDiff < dist[nrow][ncol]){
                    dist[nrow][ncol]= newDiff;
                    pq.push({dist[nrow][ncol],{ nrow,ncol}});
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

 