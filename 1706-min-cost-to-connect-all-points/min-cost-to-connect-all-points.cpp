class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> vis(n,0);
         priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        pq.push({0,0});
        int sum =0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]==1)continue;
            vis[node]=1;
            sum+=cost;
            for(int i =0 ; i< n ; i++){
                if(!vis[i]){
                    int wt = abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                    pq.push({wt,i}); // points[node][0] -- node is int not vector so if node 2 then 
                    //   on points 2nd position element and index 0 so points[2][0] ==3 and points[2][1]==10
                }
            }
        }
        return sum;
    }
};