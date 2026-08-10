class Solution {
    bool DFS(int node,
         int dest,
         vector<vector<int>>& adj,
         vector<int>& vis){

    if(node == dest)
        return true;

    vis[node] = 1;

    for(auto it : adj[node]){

        if(!vis[it]){

            if(DFS(it,dest,adj,vis))
                return true;
        }
    }

    return false;
}
public:
    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries) {



        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }
/*
        vector<vector<bool>> pre(
            numCourses,
            vector<bool>(numCourses, false));

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto nxt : adj[node]) {

                pre[node][nxt] = true;

                for (int i = 0; i < numCourses; i++) {
                    if (pre[i][node])
                        pre[i][nxt] = true;
                }

                indegree[nxt]--;

                if (indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        vector<bool> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            ans.push_back(pre[u][v]);
        }

        return ans;
        */

        vector<bool> ans;

    for(int i=0;i<queries.size();i++){

    int src  = queries[i][0];
    int dest = queries[i][1];

    vector<int> vis(numCourses,0);

    ans.push_back(
        DFS(src,dest,adj,vis)
    );
}
        return ans;
    }
    
};