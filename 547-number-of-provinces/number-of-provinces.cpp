class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {

            parent[pu] = pv;

        }
        else if (rank[pu] > rank[pv]) {

            parent[pv] = pu;

        }
        else {

            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
/*
    void BFS(int start, vector<vector<int>>& adj, vector<bool>& vis) {

        queue<int> q;
        q.push(start);
        vis[start] = true;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {

                if (!vis[it]) {

                    vis[it] = true;
                    q.push(it);

                }
            }
        }
    }
*/


    int findCircleNum(vector<vector<int>>& isConnected) {

        // int n = isConnected.size();
/*
        vector<vector<int>> adj(n);

        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (isConnected[i][j] == 1 && i != j) {

                    adj[i].push_back(j);

                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                cnt++;

                BFS(i, adj, vis);

            }
        }

        return cnt;
         */
         int n = isConnected.size();

        DSU ds(n);

        // Union all connected cities
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (isConnected[i][j] == 1) {

                    ds.unionByRank(i, j);
                }
            }
        }

        // Count ultimate parents
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (ds.find(i) == i)
                cnt++;
        }

        return cnt;
       
    }
};