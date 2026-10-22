class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        unordered_map<char, int> freq;
        for (auto it : tasks)
            freq[it]++;
        for (auto it : freq) {
            pq.push(it.second);
        }
        int time = 0;
        while (!pq.empty() || !q.empty()) {
            time++;

            while (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }
            if (!pq.empty()) {
                int top = pq.top();
                pq.pop();
                if (top > 1) {
                    q.push({top - 1, time + n + 1});
                }
            }
        }
        return time;
    }
};