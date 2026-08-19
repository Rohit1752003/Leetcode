class Solution {
    int solve(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp){
        if(i<0 || j <0 )return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] =  1+ solve(i-1, j-1, s1, s2, dp);

       return dp[i][j] =
            max(
                solve(i-1, j, s1, s2, dp),
                solve(i, j-1, s1, s2, dp)
            );
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // vector<vector<int>> dp(n , vector<int> (m , -1));
        // return solve( n-1, m-1, text1, text2 , dp);
    

        // Tabulation 
         vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));
         for(int i =1 ; i <= n ; i++){
            for(int j =1 ; j <= m ; j++){
                     dp[i][0] = 0 ;
                     dp[0][j] = 0;

                if(text1[i-1] == text2[j-1]){
                 dp[i][j] = 1+ dp[i-1][j-1];
                }else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
         }
        return dp[n][m];
    }
};