class Solution {
   bool solve(int i,
               int target,
               vector<int>& nums,
               vector<vector<int>>& dp){

        if(target == 0)
            return true;
       
        if(i == 0)
            return nums[0] == target;

        if(dp[i][target] != -1)
            return dp[i][target];

        bool notTake =
            solve(i-1,target,nums,dp);

        bool take = false;

        if(nums[i] <= target)
            take =
            solve(i-1,
                  target-nums[i],
                  nums,
                  dp);

        return dp[i][target] =
               take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(),0);
        int k = total/2;
         if(total %2 != 0 )return false;

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