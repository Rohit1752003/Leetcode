
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Case 1: No children
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // Case 2: No left child
            else if (!root->left) {
                TreeNode* node = root->right;
                delete root;
                return node;
            }

            // Case 2: No right child
            else if (!root->right) {
                TreeNode* node = root->left;
                delete root;
                return node;
            }

            // Case 3: Two children
            else {
                TreeNode* pred = root->left;
                while (pred->right) {
                    pred = pred->right;
                }

                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }

        return root;
    }
};
