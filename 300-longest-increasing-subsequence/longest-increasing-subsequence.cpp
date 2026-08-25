class Solution {
  int solve(int ind, int prevInd, vector<int>& nums,
          vector<vector<int>>& dp) {

    // Base case
    if(ind == nums.size())
        return 0;

    if(dp[ind][prevInd + 1] != -1)
        return dp[ind][prevInd + 1];

    // Not take
    int notTake = solve(ind + 1, prevInd, nums, dp);

    // Take
    int take = 0;

    if(prevInd == -1 || nums[ind] > nums[prevInd]) {
        take = 1 + solve(ind + 1, ind, nums, dp);
    }

    return dp[ind][prevInd + 1] = max(take, notTake);
}
public:
int lengthOfLIS(vector<int>& nums) {

    int n = nums.size();

    // prevInd ranges from -1 to n-1
    // +1 converts -1 into index 0
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // return solve(0, -1, nums, dp);


    // Tabulation 
    int ans = INT_MIN;
    vector<int> dp ( n+1 , 1);
    for(int i = 0  ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i] , dp[j]+1);
            }
        }
        ans = *max_element(dp.begin() , dp.end());
    }
    return ans;

}
};