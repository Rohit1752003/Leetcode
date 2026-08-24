class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0 , mini= prices[0];
        int n = prices.size();
        for(int i = 1 ; i < n ; i++){
                maxProf = max(maxProf , prices[i]- mini);
                mini = min( mini , prices[i]);
        }
        return maxProf;

    }
};