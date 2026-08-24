class Solution {
     int solve(int i , int buy ,int fee , vector<int>& nums, vector<vector<int>> &dp ){
        if(i == nums.size())return 0;
        if(dp[i][buy] != -1)return dp[i][buy];

        if(buy){
            int take = -nums[i] + solve(i+1, 0 ,fee, nums , dp);
            int notTake = solve(i+1 , 1 ,fee, nums, dp);
            return dp[i][buy] = max(take  , notTake);
        }
        else {
            int sell = (nums[i] - fee) + solve(i+1 , 1, fee,nums, dp);
            int notSell = solve(i+1 , 0 , fee,nums , dp);
            return dp[i][buy] = max(sell , notSell);
        }
    }

        
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int> (2, -1));
        return solve(0 , 1,fee , prices , dp );
    }
};