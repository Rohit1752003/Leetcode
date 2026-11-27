class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n == 0) return 0;

        vector<pair<int, int>> nums;

        for (int i = 0; i < n; i++) {
            nums.push_back({intervals[i][0], intervals[i][1]});
        }

        sort(nums.begin(), nums.end());

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        int stops = 0;
        int i = 0;

        while (i < n) {

            if (pq.empty()) {
                stops++;
                pq.push({nums[i].second, stops});
                i++;
            }
            else if (pq.top().first < nums[i].first) {

                int platform = pq.top().second;
                pq.pop();

                pq.push({nums[i].second, platform});
                i++;
            }
            else {
                stops++;
                pq.push({nums[i].second, stops});
                i++;
            }
        }

        return pq.size();
    }
};