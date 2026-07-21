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
};