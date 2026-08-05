class Solution {
    int cost(int i ,vector<int>& nums,vector<int>& dp){
        int n = nums.size();
         
        if(i >= n)return 0;
      
        if(dp[i]!=-1)return dp[i];
    
           int   include = nums[i] + cost(i+2,nums,dp);
             int  exclude= cost(i+1,nums,dp);

            return dp[i]= max(include , exclude);
       
        
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return cost(0,nums,dp);
    }
};