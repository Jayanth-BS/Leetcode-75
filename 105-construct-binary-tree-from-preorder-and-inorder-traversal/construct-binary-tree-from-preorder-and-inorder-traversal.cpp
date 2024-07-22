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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0)
        return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        int m = find(inorder.begin(), inorder.end(),preorder[0])-inorder.begin();

        if(m>0){
            vector<int> lin(inorder.begin(),inorder.begin()+m);
            vector<int> lpre(preorder.begin()+1,preorder.begin()+1+m);
            root->left =  buildTree(lpre,lin);
        }
        else
        root->left = nullptr;

        if(inorder.size()-m>0){
            vector<int> rin(inorder.begin()+m+1,inorder.end());
            vector<int> rpre(preorder.begin()+m+1,preorder.end());
            root->right = buildTree(rpre,rin);
         }
        else
            root->right = nullptr;
        return root;
    }
};