class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<pair<int, pair<int, int>>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({times[i][0], {times[i][1], i}});
        }

        sort(arr.begin(), arr.end());

        // {leavingTime, chairNumber}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > occupied;

        // Available chair numbers
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > free;

        int nextChair = 0;

      for(int i = 0 ; i < n ; i++){
        int arrival  = arr[i].first;
        int leaving = arr[i].second.first;
        int index = arr[i].second.second;
        while(!occupied.empty() && occupied.top().first <= arrival ){
            free.push(occupied.top().second);
            occupied.pop();
        }

        int chair ;

        if(!free.empty()){
            chair = free.top();
            free.pop();
        }
        else{
            chair = nextChair++;
        }

        if(index == targetFriend)return chair;

        occupied.push({leaving , chair});
      }

        return -1;
    }
};