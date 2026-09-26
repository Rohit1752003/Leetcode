/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int solve(TreeNode* root ,int &targetSum ,  int currSum  ){
               if (!root)
            return 0;

        currSum += root->val;

        if (!root->left && !root->right) {
            if (currSum == targetSum)
                return 1;

            return 0;
        }

        int left = solve(root->left, targetSum, currSum);
        int right = solve(root->right, targetSum, currSum);

        return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum ) {
        // if (!root) return false; // empty node cannot form path

        // currentSum += root->val;

        // // if leaf node, check sum
        // if (!root->left && !root->right) {
        //     return currentSum == targetSum;
        // }

        // // recursively check left and right subtrees
        // return hasPathSum(root->left, targetSum, currentSum) 
        //     || hasPathSum(root->right, targetSum, currentSum);
        return solve(root , targetSum , 0);
    }
};
