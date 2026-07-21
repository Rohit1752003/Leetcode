class Solution {
    private:
    bool BFS(int node, vector<vector<int>>& graph , vector<int>& color){
        queue<int> q;
        color[node]=0;
        q.push(node);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : graph[node]){
                if(color[it]==-1){
                    color[it] =! color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
         vector<int> color(n , -1);
         for(int i =0 ; i < n ;i++ ){
            if(color[i]==-1){
                if(BFS(i,graph,color)==false)return false;
            }
         }
         return true;
    }
};