class Solution {
    const int MOD = 1e9 + 7;

    long long dfs(int node, int dest,
                  vector<vector<pair<int,int>>> &adj,
                  vector<long long> &dp,
                  vector<long long> &dist) {

        if (node == dest)
            return 1;

        if (dp[node] != -1)
            return dp[node];

        long long ways = 0;

        for (auto &it : adj[node]) {

            int adjNode = it.first;
            int wt = it.second;

            if (dist[node] + wt == dist[adjNode]) {
                ways = (ways + dfs(adjNode, dest, adj, dp, dist)) % MOD;
            }
        }

        return dp[node] = ways;
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // ---------- Dijkstra ----------
        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0,0});

        while (!pq.empty()) {

            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto &it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                if (dis + wt < dist[adjNode]) {

                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // ---------- Count Paths ----------
        vector<long long> dp(n, -1);

        return dfs(0, n - 1, adj, dp, dist);
    }
};