class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
          int n = nums.size();
        
        vector<int> dp(n, 1), parent(n);
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
            parent[i] = i;

        // Build DP
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < i; j++) {
                
                if(nums[i] % nums[j] == 0 &&
                   dp[j] + 1 >= dp[i]) {
                    
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }

        // Find where the largest subset ends
        int lastInd = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(dp[i] > dp[lastInd])
                lastInd = i;
        }

        // Reconstruct answer
        vector<int> ans;
        
        while(parent[lastInd] != lastInd) {
            
            ans.push_back(nums[lastInd]);
            lastInd = parent[lastInd];
        }
        
        ans.push_back(nums[lastInd]);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};