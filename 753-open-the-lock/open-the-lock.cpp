class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());

        if (dead.count("0000"))
            return -1;

        queue<pair<string, int>> q;
        unordered_set<string> vis;

        q.push({"0000", 0});
        vis.insert("0000");

        while (!q.empty()) {

            auto [curr, steps] = q.front();
            q.pop();

            if (curr == target)
                return steps;

            for (int i = 0; i < 4; i++) {

                string up = curr;
                string down = curr;

                // Rotate wheel up
                up[i] = (up[i] == '9') ? '0' : up[i] + 1;

                // Rotate wheel down
                down[i] = (down[i] == '0') ? '9' : down[i] - 1;

                if (!dead.count(up) && !vis.count(up)) {
                    vis.insert(up);
                    q.push({up, steps + 1});
                }

                if (!dead.count(down) && !vis.count(down)) {
                    vis.insert(down);
                    q.push({down, steps + 1});
                }
            }
        }

        return -1;
    }
};