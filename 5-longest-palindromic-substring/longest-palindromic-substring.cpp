class Solution {
public:
    string longestPalindrome(string s) {

        string text1 = s;
        string text2 = s;

        reverse(text2.begin(), text2.end());

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        int maxLen = 0;
        int start = 0;

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                if(text1[i-1] == text2[j-1]) {

                    dp[i][j] =
                        1 + dp[i-1][j-1];

                    int len = dp[i][j];

                    // Start of this substring in text1
                    int start1 = i - len;

                    // Corresponding mirrored start in text1
                    int start2 = n - j;

                    // They must refer to the same interval
                    if(start1 == start2 && len > maxLen) {

                        maxLen = len;
                        start = start1;
                    }

                }
                else {

                    dp[i][j] = 0;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};