class Codec {
    string BFS(TreeNode* root, string& ans) {
        if (!root)
            return "";

        queue<TreeNode*> q;
        q.push(root);
          ans += to_string(root->val) + ",";
        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

          

            if (node->left) {
                q.push(node->left);
                ans += to_string(node->left->val) + ",";
            }
            else {
                ans += "#,";
            }

            if (node->right) {
                q.push(node->right);
                 ans += to_string(node->right->val) + ",";
            }
            else {
                ans += "#,";
            }
        }

        return ans;
    }

    TreeNode* solve(string& ans) {

        if (ans.size() == 0)
            return NULL;

        stringstream s(ans);
        string str;

        // Root
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // LEFT
            getline(s, str, ',');

            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // RIGHT
            getline(s, str, ',');

            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }

public:

    string serialize(TreeNode* root) {
        string ans = "";
        return BFS(root, ans);
    }

    TreeNode* deserialize(string data) {
        return solve(data);
    }
};