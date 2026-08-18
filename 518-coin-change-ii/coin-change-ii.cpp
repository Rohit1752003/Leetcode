class Solution {
     int solve(int i , int target ,vector<int>& arr, vector<vector<int>> &dp ){
        //  if(target == 0 ) return 1;
         if(target ==0 && (target + arr[i])%2 == 0 )return 1;
        if(i == 0){
            if(target % arr[0] == 0) return 1;
           
            return 0;
        }
        
        if(dp[i][target] != -1)return dp[i][target];
        int notTake = solve(i-1, target , arr, dp);
        int take = 0;
        if(arr[i]<= target){
             take =    solve(i, target-arr[i] , arr, dp);
        }   
       
        return dp[i][target]= take + notTake;
        
    }
public:
    int change(int amount, vector<int>& coins) {
         int n = coins.size();
        vector<vector<int>>dp (n , vector<int>(amount+1 , -1));
       
       
          return   solve(n-1, amount, coins, dp);

        
    }
};