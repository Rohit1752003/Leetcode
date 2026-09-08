class Solution {
    int cost(int i ,vector<int>& nums,vector<int>& dp){
         int n = nums.size();
        //  if(i == n-1 )return nums[n-1];
         if(i > n-1)return 0;
         if(dp[i] != -1)return dp[i];
         int exclude = cost(i+1 ,nums , dp);
         int include = nums[i] + cost(i+2, nums , dp);
         return dp[i] = max(exclude , include);
        
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return cost(0,nums,dp);
    }
};