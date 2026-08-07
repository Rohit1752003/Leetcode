class Solution {
    int solve(int i, vector<pair<int,int>> &v, vector<int> &dp) {

        if (i >= v.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int include = v[i].second;

        // If next value is consecutive, skip it
        if (i + 1 < v.size() && v[i + 1].first == v[i].first + 1)
            include += solve(i + 2, v, dp);
        else
            include += solve(i + 1, v, dp);

        int exclude = solve(i + 1, v, dp);

        return dp[i] = max(include, exclude);
    }

public:
    int deleteAndEarn(vector<int>& nums) {

        map<int,int> mp;

        for (int x : nums)
            mp[x] += x;        // store total points, not frequency

        vector<pair<int,int>> v;

        for (auto &it : mp)
            v.push_back(it);

        vector<int> dp(v.size(), -1);

        return solve(0, v, dp);
    }
};