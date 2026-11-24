class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end(),
     [](const auto& a, const auto& b) {
         return a[1] < b[1];
     });

     int arrows = 0;
     int i = 0 ;
     
     while( i < n ){
        arrows++;
        int position = points[i][1];
        while(i < n && points[i][0] <= position )i++;
     }
     return arrows;
    }
};