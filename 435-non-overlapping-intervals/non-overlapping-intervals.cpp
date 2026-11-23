class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin() , intervals.end() ,[](const auto &a , const auto &b){
            return a[1] < b[1];
        });
        int i = 0 ;
        int cnt = 0 ;
        int lastEnd = INT_MIN;
        while( i < n ){
            if(intervals[i][0] >= lastEnd){
                cnt++;
              lastEnd = intervals[i][1];
            }
            i++;
        }
        return n-cnt;
    }
};