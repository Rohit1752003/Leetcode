class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();

        if(time == 0) return 0;

        sort(clips.begin(), clips.end());

        if(n == 0 || clips[0][0] != 0) return -1;

        int covered = 0;
        int i = 0;
        int cnt = 0;

        priority_queue<pair<int,int>> pq;

        while(covered < time) {

            while(i < n && covered >= clips[i][0]) {
           
                pq.push({clips[i][1], clips[i][0]});
                i++;
            }

            if(pq.empty()) return -1;

            if(pq.top().first <= covered) return -1;

            covered = pq.top().first;
            pq.pop();
            cnt++;
        }

        return cnt;
    }
};