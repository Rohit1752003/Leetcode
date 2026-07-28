class Solution {
    private:
     bool BFS(int node ,vector<vector<int>> &grid, vector<int> &color){
        queue<int>q;
        color[node]=0;
        q.push(node);
       
        while(!q.empty()){
            int node = q.front();
           
            q.pop();
            for(auto it : grid[node]){
                if(color[it]==-1){
                    color[it] = 1- color[node];
                    q.push(it);
                    
                }
                else if( color[it]==color[node] )return false;
            }
        }
        return true;
        
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto it : dislikes){
            int u = it[0];
            int v =  it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(n+1,-1);
        for(int i =1; i< n+1; i++){
            if(color[i]==-1){
                if(BFS(i,adj,color)==false)return false;
            }
        }
        return true;
    }
};