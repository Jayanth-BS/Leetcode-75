/**
The evaluation of a node is as follows:

If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
Return the boolean result of evaluating the root node.
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
    bool post(TreeNode* root){
        if(root->left == NULL && root->right == NULL)
        return root->val;

        bool l = post(root->left);
        bool r = post(root->right);
        if(root->val == 2)
        return l|r;
        else 
        return l&r;
    }
    bool evaluateTree(TreeNode* root) {
        return post(root);
    }
};
