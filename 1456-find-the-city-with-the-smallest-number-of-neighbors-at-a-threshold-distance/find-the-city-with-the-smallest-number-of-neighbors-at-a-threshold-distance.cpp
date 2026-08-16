class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        const int INF = 1e8;

        vector<vector<int>> dist(
            n,
            vector<int>(n, INF)
        );

        // Distance from node to itself
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Graph is UNDIRECTED
        for(auto it : edges) {

            int u = it[0];
            int v = it[1];
            int w = it[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall
        for(int k = 0; k < n; k++) {

            for(int i = 0; i < n; i++) {

                for(int j = 0; j < n; j++) {

                    if(dist[i][k] != INF &&
                       dist[k][j] != INF) {

                        dist[i][j] =
                            min(dist[i][j],
                                dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Find city with minimum reachable cities
        // Tie -> larger city index
        int minCount = INT_MAX;
        int ans = -1;

        for(int i = 0; i < n; i++) {

            int cnt = 0;

            for(int j = 0; j < n; j++) {

                if(i != j &&
                   dist[i][j] <= distanceThreshold) {

                    cnt++;
                }
            }

            if(cnt <= minCount) {
                minCount = cnt;
                ans = i;
            }
        }

        return ans;
    }
};