class Solution {
    int solve(int i, int j, vector<int>& nums,
              vector<vector<int>>& dp) {

        if(i + 1 == j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;

        for(int k = i + 1; k < j; k++) {

            int coins = nums[i] * nums[k] * nums[j]
                      + solve(i, k, nums, dp)
                      + solve(k, j, nums, dp);

            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, nums, dp);
    }
};