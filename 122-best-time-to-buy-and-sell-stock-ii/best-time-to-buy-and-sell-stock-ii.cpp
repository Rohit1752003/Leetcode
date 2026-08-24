class Solution {
    int solve(int i , int buy ,vector<int>& nums, vector<vector<int>> &dp ){
        if(i == nums.size())return 0;
        if(dp[i][buy] != -1)return dp[i][buy];

        if(buy){
            int take = -nums[i] + solve(i+1, 0 , nums , dp);
            int notTake = solve(i+1 , 1 , nums, dp);
            return dp[i][buy] = max(take  , notTake);
        }
        else {
            int sell = nums[i] + solve(i+1 , 1, nums, dp);
            int notSell = solve(i+1 , 0 , nums , dp);
            return dp[i][buy] = max(sell , notSell);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int> (2, -1));
        return solve(0 , 1, prices , dp );
    }
};