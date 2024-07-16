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
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == nullptr || root== p || root == q) return root;
        TreeNode* left = lca(root->left,p,q); 
        TreeNode* right = lca(root->right,p,q);
        if(left == nullptr)
        return right;
        if(right == nullptr)
        return left;
        return root;
    }
    TreeNode* find(TreeNode* root, int start){
        if(root == nullptr || root->val == start)
        return root;
        TreeNode* left = find(root->left,start);
        if (left != nullptr) return left;
        return find(root->right, start);
    }
    
    int findlevel(TreeNode* root, int start, int level){
        if(root == nullptr) return -1; 
        if(root->val == start) return level;
        int left = findlevel(root->left,start,level+1);
        if(left==-1) return findlevel(root->right,start,level+1);
        return left;
    }
    
    bool find(TreeNode* root, int start,string &s){
        if(root == nullptr) return 0;
        if(root->val == start) return 1;
        s += "L";
        if(find(root->left,start,s)) return 1;
        s.pop_back();
       s += "R";
        if(find(root->right,start,s)) return 1;
        s.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* start = find(root, startValue);
        TreeNode* end = find(root, destValue);
        TreeNode* lc = lca(root,start, end);
        int  l = findlevel(lc,startValue,0);
        string s(l,'U');
        find(lc,destValue,s);
        return s;
    }
};