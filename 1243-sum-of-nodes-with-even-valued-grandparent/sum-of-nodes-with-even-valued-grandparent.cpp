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
public:
    int sum =0;
    void inorder(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr)
        return;
        if(root->val%2 == 0 ){
            if(root->left != nullptr){
        if(root->left->left)
        sum += root->left->left->val;
       if(root->left->right)
        sum += root->left->right->val;
        }
        if(root->right != nullptr){        
            if(root->right->right)
        sum += root->right->right->val;
         if(root->right->left)
        sum += root->right->left->val;
        }
        }
        if(root->left) inorder(root->left);
        if(root->right) inorder(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        inorder(root);
        return sum;
    }
};