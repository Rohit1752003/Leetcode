class Solution {
      private:
    vector<int> BFS(vector<vector<int>>& grid,vector<int>& indegree  ){
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
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>> grid(numCourses);
        for(auto it : prerequisites){
            grid[it[1]].push_back(it[0]);
        }
                vector<int> indegree(numCourses,0);
        for(int i =0 ; i < numCourses ; i++){
            for(auto it : grid[i]){
                indegree[it]++;
            }
        }

        
    //   stack<int>st;
        // for(int i =0 ; i< V ; i++){
        //     if(!vis[i]){
                
               
        //     }
        // }

      
             vector<int> ans = BFS(grid,indegree);
             if(numCourses != ans.size())return{};
             return ans;

    }
};