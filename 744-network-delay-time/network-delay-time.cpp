class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});   // Directed graph
        }

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto &it : adj[node]) {

                int adjNode = it.first;
                int edgeWt = it.second;

                if (dis + edgeWt < dist[adjNode]) {

                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
        }

        return *max_element(dist.begin() + 1, dist.end());
    }
};