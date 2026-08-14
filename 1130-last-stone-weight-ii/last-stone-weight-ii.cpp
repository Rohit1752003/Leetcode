class Solution {
    
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int n = stones.size();
        int total = accumulate(stones.begin(),
                       stones.end(),0);

vector<vector<bool>> dp(
    n,
    vector<bool>(total+1,false));

for(int i=0;i<n;i++)
    dp[i][0] = true;

dp[0][stones[0]] = true;

for(int i=1;i<n;i++){
    for(int target=1;
        target<=total;
        target++){

        bool notTake =
            dp[i-1][target];

        bool take = false;

        if(stones[i] <= target)
            take =
            dp[i-1][target-stones[i]];

        dp[i][target] =
            take || notTake;
    }
}

int ans = INT_MAX;

for(int s1=0;
    s1<=total/2;
    s1++){

    if(dp[n-1][s1])
        ans = min(ans,
                  total - 2*s1);
}

return ans;



    }
};