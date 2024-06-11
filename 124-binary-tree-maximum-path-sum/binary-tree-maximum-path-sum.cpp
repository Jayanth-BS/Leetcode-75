class Solution {
public:
int mx = INT_MIN;
    int f(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = max(0,f(root->left));
        int right = max(0, f(root->right));
        mx = max(mx,root->val + left + right);
        
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root){
        f(root);
        return mx;
    }
};