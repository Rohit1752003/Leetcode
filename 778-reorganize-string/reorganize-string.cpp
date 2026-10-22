
class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        queue<pair<pair<int, char>, int>> q;
        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        int time = 0;
        string ans = "";

        while (!pq.empty() || !q.empty()) {
            time++;

            while (!q.empty() && q.front().second <= time) {
               
                    pq.push({
                        q.front().first.first,
                        q.front().first.second
                    });
                
                q.pop();
            }

            if (!pq.empty()) {
                auto [cnt, ch] = pq.top();
                pq.pop();

                ans += ch;

                if (cnt > 1) {
                    q.push({{cnt - 1, ch}, time + 2});
                }
            } else if (!q.empty()) {
                return "";
            }
        }

        return ans;
    }
};
