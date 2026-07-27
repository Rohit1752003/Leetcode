class Solution {
      private:
    /*vector<int> BFS(vector<vector<int>>& grid,vector<int>& indegree  ){
        queue<int>q;
        for(int i = 0 ; i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                // vis[i]=1;
            }
        }
                 vector<int> ans;

         while(!q.empty()){
             int node = q.front();
             q.pop();
             ans.push_back(node);
              for(auto it : grid[node]){
                 
                     indegree[it]--;
            
                 if(indegree[it]==0)
                     q.push(it);
                     

                 
             
         }
             
         }
         return ans;   
     }
     */
     private:
    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis,
             vector<int>& pathVis,
             stack<int>& st) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjNode : adj[node]) {

            if (!vis[adjNode]) {

                if (dfs(adjNode, adj, vis, pathVis, st))
                    return true;
            }
            else if (pathVis[adjNode]) {
                return true;        // Cycle found
            }
        }

        pathVis[node] = 0;
        st.push(node);

        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       
        //         vector<int> indegree(numCourses,0);
        // for(int i =0 ; i < numCourses ; i++){
        //     for(auto it : grid[i]){
        //         indegree[it]++;
        //     }
        // }

        
      vector<vector<int>> adj(numCourses);

        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        stack<int> st;

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {

                if (dfs(i, adj, vis, pathVis, st))
                    return {};
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};