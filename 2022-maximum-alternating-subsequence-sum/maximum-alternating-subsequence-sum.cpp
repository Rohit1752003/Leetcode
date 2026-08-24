class Solution {
    long long solve(int i, int sign,
                    vector<int>& nums,
                    vector<vector<long long>>& dp) {

        if(i == nums.size())
            return 0;

        if(dp[i][sign] != -1)
            return dp[i][sign];

        if(sign == 1) {

            long long take =
                nums[i] + solve(i+1, 0, nums, dp);

            long long notTake =
                solve(i+1, 1, nums, dp);

            return dp[i][sign] =
                max(take, notTake);
        }

        else {

            long long take =
                -nums[i] + solve(i+1, 1, nums, dp);

            long long notTake =
                solve(i+1, 0, nums, dp);

            return dp[i][sign] =
                max(take, notTake);
        }
    }

public:
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();

        vector<vector<long long>> dp(
            n,
            vector<long long>(2, -1)
        );

        return solve(0, 1, nums, dp);
    }
};