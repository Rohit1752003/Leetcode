class Solution {
public:
    int ans =0;
    //  1 st Approach 
    // Returns height of tree in terms of nodes
    /*int height(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    */

    // 2nd Approach 
    int bfs(TreeNode* root){
         if(!root) return 0;
        int left = bfs(root->left);
        int right = bfs(root->right);
        ans = max(ans, left + right); // edges
        return 1 + max(left, right);
    }
     int solve(TreeNode* root){
        if(!root)return 0;
        
        int left =  solve(root->left);
        int right =  solve(root->right);
          ans = max(ans, left + right); // edges
        return 1 +  max(left , right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       /* if(root == NULL) return 0;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        // Diameter passing through root
        int rootDiameter = height(root->left) + height(root->right); // edges
        return max(rootDiameter, max(leftDiameter, rightDiameter));
*/
        solve(root);
        return ans;

       
    }
};
