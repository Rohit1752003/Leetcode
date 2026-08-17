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
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp (n , vector<int>(amount+1 , -1));
       
        int ans =
            solve(n-1, amount, coins, dp);

        return ans >= 1e8 ? -1 : ans;
    }
};