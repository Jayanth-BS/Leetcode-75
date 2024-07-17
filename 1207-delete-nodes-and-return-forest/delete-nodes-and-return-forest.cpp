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
    vector<TreeNode*>ans;
    unordered_set<int>st;
    void dfs(TreeNode* root,TreeNode* par,int flag)
    {
        if(!root)return ;
        dfs(root->left,root,0);
        dfs(root->right,root,1);
        if(st.find(root->val)!=st.end()){
            if(root->left)ans.push_back(root->left);
            if(root->right)ans.push_back(root->right);
            if(flag==0)par->left=NULL;
            else par->right=NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto x:to_delete)st.insert(x);
        if(st.find(root->val)==st.end()){
            ans.push_back(root);
        }
        TreeNode* dummy=new TreeNode(-1,root,NULL);
        dfs(root,dummy,-1);
        return ans;
    }

};