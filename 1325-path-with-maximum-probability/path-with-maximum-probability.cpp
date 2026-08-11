class Solution {
    double BFS( vector<vector<pair<int ,double>>>& adj, vector<double>& dist, int src, int dest){
          priority_queue<pair<double,int>> q;

        dist[src] =1.0;
        q.push({1.0, src});
        while(!q.empty()){
            double prob = q.top().first;
            int node = q.top().second;
            q.pop();
            if(prob < dist[node])continue;
            if(node == dest)return prob;
            for(auto it : adj[node]){
                int adjNode = it.first;
                double newProb  = it.second;
                if(newProb * prob > dist[adjNode]){
                    dist[adjNode] = newProb * prob;
                    q.push({dist[adjNode], adjNode});
                }
            }
        }
        if(dist[dest] == -1)
        return 0.0;
       return dist[dest];
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
 

    vector<vector<pair<int,double>>> adj(n);

    for(int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob}); // undirected
        }
        vector<double> dist(n , 0.0);
        return BFS(adj, dist, start_node, end_node);
    }
};