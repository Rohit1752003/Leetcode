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
                    pq.push({wt,i});
                }
            }
        }
        return sum;
    }
};