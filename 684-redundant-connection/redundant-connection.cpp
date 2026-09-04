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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU ds(n+1);
       
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(ds.find(u)!= ds.find(v))
            ds.unionBySize(u , v);
            else if (ds.find(u) == ds.find(v)) return {u,v};
        }
        return {-1, -1};
    }
};