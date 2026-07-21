/*
class Solution {
     private:
   bool BFS(int V, vector<vector<int>>& adj, vector<int>& indegree) {

    queue<int> q;

    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    int cnt = 0;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        cnt++;

        for(auto it : adj[node]) {

            indegree[it]--;

            if(indegree[it] == 0)
                q.push(it);
        }
    }

    return cnt == V;
} 
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
           vector<vector<int>> adj(numCourses);

    for(auto &it : prerequisites) {
        adj[it[1]].push_back(it[0]);
    }

    vector<int> indegree(numCourses, 0);

    for(int i = 0; i < numCourses; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    return BFS(numCourses, adj, indegree);
    }
};  */
class Solution {
    private:
    bool DFS(int node, vector<vector<int>>& grid, vector<int>& vis,vector<int>& pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it : grid[node]){
            if(!vis[it]){
                if(DFS(it,grid,vis,pathVis)==true)return true;
            }
            else if (pathVis[it])return true;
        }
        pathVis[node]=0;
        return false;
    }
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> vis(numCourses,0);
          vector<int> visPath(numCourses,0);
          vector<vector<int>>adj(numCourses);
            for(auto it :prerequisites ){
                    adj[it[1]].push_back(it[0]);
            }

        for(int i =0 ;i <numCourses;i++ ){
            if(!vis[i]){
                if(DFS(i,adj,vis ,visPath)==true)return false;
            }
        }
        return true;
    }
};