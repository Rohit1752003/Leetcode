class Solution {
  int solve(int i,
          int buy,
          int cap,
          vector<int>& nums,
          vector<vector<vector<int>>>& dp) {

    if(i == nums.size() || cap == 0)
        return 0;

    if(dp[i][buy][cap] != -1)
        return dp[i][buy][cap];

    if(buy) {

        int take =
            -nums[i] +
            solve(i+1, 0, cap, nums, dp);

        int notTake =
            solve(i+1, 1, cap, nums, dp);

        return dp[i][buy][cap] =
            max(take, notTake);
    }

    else {

        int sell =
            nums[i] +
            solve(i+1, 1, cap-1, nums, dp);

        int notSell =
            solve(i+1, 0, cap, nums, dp);

        return dp[i][buy][cap] =
            max(sell, notSell);
    }
}
public:
    int maxProfit(vector<int>& prices) {
       
    int n = prices.size();

    vector<vector<vector<int>>> dp(
        n,
        vector<vector<int>>(
            2,
            vector<int>(3, -1)
        )
    );

    return solve(0, 1, 2, prices, dp);
    }
};