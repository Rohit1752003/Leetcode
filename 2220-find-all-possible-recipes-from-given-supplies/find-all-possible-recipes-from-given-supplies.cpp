class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;

        // Build graph
        for (int i = 0; i < recipes.size(); i++) {

            indegree[recipes[i]] = ingredients[i].size();

            for (auto &ing : ingredients[i]) {
                adj[ing].push_back(recipes[i]);
            }
        }

        queue<string> q;

        // Initially available supplies
        for (auto &s : supplies)
            q.push(s);

        vector<string> ans;

        while (!q.empty()) {

            string item = q.front();
            q.pop();

            for (auto &recipe : adj[item]) {

                indegree[recipe]--;

                if (indegree[recipe] == 0) {

                    ans.push_back(recipe);

                    // Newly prepared recipe becomes a supply
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};