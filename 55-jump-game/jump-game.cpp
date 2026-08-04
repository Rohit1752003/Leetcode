class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool > dp(n+1, false);
        if(dp[n-1]==true)return true;
        dp[0] = true;
        for(int i =0 ; i< n ; i++){
            if(!dp[i])continue;
            for(int j =1 ; j <=nums[i]; j++){
                if(i+j >n)break;
              
                dp[i+j]=true;

            }
        }
        return dp[n-1];
    }
};