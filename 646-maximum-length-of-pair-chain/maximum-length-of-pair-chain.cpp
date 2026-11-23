class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int m = pairs[0].size();
        vector<pair<int , int>> nums;
        for(int i = 0 ; i < n ; i++){
            nums.push_back({pairs[i][0] , pairs[i][1]});
        }
           sort(nums.begin(), nums.end(),
             [](const auto& a, const auto& b) {
                 return a.second < b.second;
             });
        int cnt = 0 ;
        int lastEnd = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            int st = nums[i].first;
            int end = nums[i].second;

            if(st > lastEnd){
                cnt++;
                lastEnd = end;
            }
        }
        return cnt;
    }
};