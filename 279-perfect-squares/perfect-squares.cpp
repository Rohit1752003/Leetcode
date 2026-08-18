class Solution {
    int solve(int i , int target ,vector<int>& arr, vector<vector<int>> &dp ){
         if(target == 0 ) return 0;
        if(i == 0){
            if(target % arr[0] == 0) return (target / arr[0]);
           
            return 1e8;
        }
        
        if(dp[i][target] != -1)return dp[i][target];
        int notTake = solve(i-1, target , arr, dp);
        int take = 1e8;
        if(arr[i]<= target){
             take = 1+  solve(i, target-arr[i] , arr, dp);
        }   
       
        return dp[i][target]= min(take, notTake);
        
    }

public:
    int numSquares(int n) {
        vector<int> ans;
        for(int i =1 ; i * i <= n ; i++){
            ans.push_back(i*i);
        }
          int index = ans.size();
        vector<vector<int>>dp (index , vector<int>(n+1 , -1));
       
       
          return   solve(index-1, n, ans, dp);
    }
};