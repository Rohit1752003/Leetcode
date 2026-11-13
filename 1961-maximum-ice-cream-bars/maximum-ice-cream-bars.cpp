class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin() , costs.end());
        if(costs[0] > coins)return 0;
        int cnt = 0;
        int i = 0 ; 
        while( i < n  && coins > 0 ){
             if(costs[i] <= coins )cnt++;
            coins -= costs[i];
            i++;
        }
      
        return cnt;
    }
};