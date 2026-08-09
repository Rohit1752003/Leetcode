class Solution {  
private:
    int BFS(int src, int dest,
            vector<vector<pair<int,int>>>& adj,
            vector<int>& dist,
            int k) {
    queue<vector<int>>q;
    dist[src]=0;
    if(src==dest)return 0;

    q.push({0,src,0}); // stops , node, cost
    while(!q.empty()){
       vector<int> curr = q.front();
        q.pop();

        int stops = curr[0];
        int node  = curr[1];
        int cost  = curr[2];
        if(stops>k)continue;
        for(auto it : adj[node]){
            int adjNode = it.first;
            int wt = it.second;
            int newWt = cost + wt;
            if(newWt < dist[adjNode]){
                dist[adjNode] = newWt;
                q.push({stops+1 , adjNode, newWt});
            }
        }
       
    }
     if(dist[dest] == INT_MAX)return -1;
        return dist[dest];
    }
   
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        vector<int> dist(n, INT_MAX);

        for (auto &it : flights) {

            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }

        return BFS(src, dst, adj, dist, k);
    }
};
 //  bellman ford 
     /*   vector<int> dist(n,1e8);
        dist[src]=0;
        for(int i =0 ; i<= k ; i++){

            vector<int> temp = dist;
                for(auto it : flights){
                    int u = it[0];
                    int v = it[1];
                    int w = it[2];
                      if (dist[u] != 1e8 && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;   
                    
                }
              
            }
            dist= temp;
           
            
        }
        
        
        // for(auto it : flights){
        //      int u = it[0];
        //             int v = it[1];
        //             int w = it[2];
        //             if(dist[u] != 1e8 && dist[u]+ w < dist[v])return {-1};
        // }
        return dist[dst] == 1e8 ? -1 : dist[dst]; */