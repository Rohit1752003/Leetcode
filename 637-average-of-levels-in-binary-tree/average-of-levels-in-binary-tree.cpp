class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> ans;

        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            double avg = (double)sum / size;
            ans.push_back(avg);
            sum=0;
        }

        return ans;
    }
};