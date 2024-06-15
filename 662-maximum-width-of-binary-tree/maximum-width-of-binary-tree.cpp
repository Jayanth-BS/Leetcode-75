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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        long long mx = 1;
        long long mod = 1e11;
        if(root!=NULL)
        {
            q.push({root,1});
        }
        while(!q.empty()){
            long long s = q.size(),f=0,b=0;
            for(int i=0;i<s;i++){
                if(i == 0)
                    f = q.front().second;
                if(i == s-1)
                    b = q.front().second;
                
                auto k = q.front();
                q.pop();
                if(k.first->left != NULL){
                    q.push({k.first->left,(2*k.second)%mod});
                }                
                if(k.first->right != NULL){
                    q.push({k.first->right,(2*k.second+1)%mod});
                }  
            }
            mx = max(b-f+1,mx);
        }
        return mx;
     }
};