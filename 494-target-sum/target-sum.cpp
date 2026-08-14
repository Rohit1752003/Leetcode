class Solution {
    int solve(int i , int target ,vector<int>& arr, vector<vector<int>> &dp ){
        if(i == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }
        
        if(dp[i][target] != -1)return dp[i][target];
        int notTake = solve(i-1, target , arr, dp);
        int take = 0;
        if(arr[i]<= target)take = solve(i-1, target-arr[i] , arr, dp);
        return dp[i][target]= take+ notTake;
        
    }

      
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int n = nums.size();

    int total =
        accumulate(nums.begin(),
                   nums.end(),0);

    if(total + target < 0)
        return 0;

    if((total + target) % 2)
        return 0;

    int k = (total + target)/2;

    vector<vector<int>> dp(
        n,
        vector<int>(k+1,-1));

    return solve(
        n-1,
        k,
        nums,
        dp);
    }
};