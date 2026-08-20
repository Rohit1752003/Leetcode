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
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.length();
        int m = rev.length();
         vector<vector<int>> dp(n , vector<int> (m , -1));
       
        return solve(n-1, m-1,  s , rev, dp);
       
    }
};