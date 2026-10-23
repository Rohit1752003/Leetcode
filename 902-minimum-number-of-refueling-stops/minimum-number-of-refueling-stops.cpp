
class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        priority_queue<int> pq;
        long long reach = startFuel;
        int stops = 0;

        for (auto& station : stations) {
            while (reach < station[0]) {
                if (pq.empty()) return -1;

                reach += pq.top();
                pq.pop();
                stops++;
            }

            pq.push(station[1]);
        }

        while (reach < target) {
            if (pq.empty()) return -1;

            reach += pq.top();
            pq.pop();
            stops++;
        }

        return stops;
    }
};
