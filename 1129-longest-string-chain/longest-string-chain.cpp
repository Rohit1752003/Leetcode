class Solution {
  bool isPredecessor(string &shorter, string &longer) {

    if(longer.size() != shorter.size() + 1)
        return false;

    int i = 0;
    int j = 0;
    int skip = 0;

    while(i < shorter.size() && j < longer.size()) {

        if(shorter[i] == longer[j]) {
            i++;
            j++;
        }
        else {

            skip++;
            j++;   // Skip character from longer

            if(skip > 1)
                return false;
        }
    }

    return true;
}
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
             [](string &a, string &b) {
                 return a.size() < b.size();
             });
        vector<int> dp(n , 1);
        for(int i =0 ; i < n ; i++){
            for(int j =0 ; j < i ; j++){
                if(isPredecessor(words[j] , words[i]) && dp[j] +1 > dp[i] ){
                         dp[i] = dp[j]+1;
                        
                }
            
            }
        }
        return *max_element(dp.begin() , dp.end());
    }
};