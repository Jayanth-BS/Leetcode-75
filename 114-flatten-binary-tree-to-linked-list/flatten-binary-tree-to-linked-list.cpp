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
    void f(TreeNode* root, vector<int> &pre){
        pre.push_back(root->val);
        if(root->left)
            f(root->left, pre);
        if(root->right)
            f(root->right,pre);
    }
    void flatten(TreeNode* root) {
        vector<int> pre;
        if(root != nullptr)
        f(root,pre);
       
        TreeNode* temp = root;
        for(int i=1;i<pre.size();i++){
             TreeNode* node = new TreeNode(pre[i]);
             temp->right = node;
             temp->left =  nullptr;
             temp = temp->right;
        }

    }
};