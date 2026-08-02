class DSU {
public:
    vector<int> parent, rank ,size;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n);
        for (int i = 0; i < n; i++){
            parent[i] = i;
            size[i]= 1;
    }
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
    void unionBySize(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {

            parent[pu] = pv;
            size[pv] += size[pu];

        }
        else {

            parent[pv] = pu;
            size[pu] += size[pv];

        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        if(connections.size() <n-1)return -1;
        int extra= 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.find(u) ==  ds.find(v))extra++;
            else {
                ds.unionByRank(u,v);
            }
        }
        int cnt=0;
        for (int i = 0; i < n; i++) {

            if (ds.find(i) == i)
                cnt++;
        }
        if(extra >= cnt-1)return cnt-1;
        return -1;

    }
};