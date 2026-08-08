class Solution {
    int solve(int i ,vector<pair<int,int>>& nums,  vector<int>& dp){
        int n = nums.size();
        if(i>=n)return 0 ;
        if(dp[i] != -1)return dp[i];
        int include = nums[i].second ;
        if(i+1 < n && nums[i+1].first == nums[i].first +1)
          include  +=   solve(i+2 , nums, dp);

       else
            include += solve(i + 1, nums, dp);
            
            int exclude = solve(i+1 , nums, dp);
            return dp[i] = max(include , exclude);
        
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums)mp[it] += it;

        vector<pair<int,int>> arr;
        for(auto it : mp) arr.push_back(it);
        sort(arr.begin(), arr.end());
        vector<int> dp(arr.size(), -1);
        return solve(0,arr, dp);
    }
};