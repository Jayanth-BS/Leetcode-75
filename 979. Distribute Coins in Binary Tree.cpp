/**
You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.
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
    int res=0;
    pair<int,int> f(TreeNode* root){
        if(!root)
            return {0,0};
        
        pair<int,int> l = f(root->left);
        pair<int,int> r = f(root->right);
        int ls = l.first;
        int lc = l.second;
        int rs = r.first; 
        int rc = r.second;
        int s = 1+ls+rs;
        int c = root->val + lc + rc;
        res += abs(s-c);
        return {s,c};

    }
    int distributeCoins(TreeNode* root) {
        f(root);
        return res;
    }
};
