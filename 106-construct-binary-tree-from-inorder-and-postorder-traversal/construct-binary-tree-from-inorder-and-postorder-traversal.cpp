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

    int findPosition(vector<int> &inOrder , int element ){
        for(int i =0 ; i < inOrder.size() ; i++){
            if(inOrder[i] == element)return i;

           
        }
         return -1;
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder , int &proIndex , int start , int end){
        if(start > end)return nullptr;

        TreeNode* node = new TreeNode(postorder[proIndex--]);
        int position = findPosition(inorder , node->val);
         node->right = build(inorder , postorder , proIndex , position + 1 , end);
        node->left = build(inorder , postorder , proIndex , start , position-1);
       
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int proIndex =postorder.size()-1;
        return build(inorder , postorder , proIndex , 0 ,  n-1);
    }
};