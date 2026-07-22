class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& graph, vector<int> indegree) {

        queue<int> q;
        vector<int> order;

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            order.push_back(node);

            for (int nxt : graph[node]) {

                indegree[nxt]--;

                if (indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        return order;
    }

public:
    vector<int> sortItems(int n, int m,
                          vector<int>& group,
                          vector<vector<int>>& beforeItems) {

        // Give every ungrouped item its own unique group
        int groupId = m;

        for (int i = 0; i < n; i++) {
            if (group[i] == -1)
                group[i] = groupId++;
        }

        // Graphs
        vector<vector<int>> itemGraph(n);
        vector<vector<int>> groupGraph(groupId);

        // Indegree arrays
        vector<int> itemIndegree(n, 0);
        vector<int> groupIndegree(groupId, 0);

        // Build graphs
        for (int curr = 0; curr < n; curr++) {

            for (int prev : beforeItems[curr]) {

                // Item dependency
                itemGraph[prev].push_back(curr);
                itemIndegree[curr]++;

                // Group dependency
                if (group[prev] != group[curr]) {
                    groupGraph[group[prev]].push_back(group[curr]);
                    groupIndegree[group[curr]]++;
                }
            }
        }

        // Topological sort of items
        vector<int> itemOrder = topoSort(itemGraph, itemIndegree);

        if (itemOrder.size() != n)
            return {};

        // Topological sort of groups
        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);

        if (groupOrder.size() != groupId)
            return {};

        // Store items according to item topo order
        unordered_map<int, vector<int>> groupItems;

        for (int item : itemOrder) {
            groupItems[group[item]].push_back(item);
        }

        // Build final answer using group order
        vector<int> ans;

        for (int grp : groupOrder) {

            for (int item : groupItems[grp])
                ans.push_back(item);
        }

        return ans;
    }
};