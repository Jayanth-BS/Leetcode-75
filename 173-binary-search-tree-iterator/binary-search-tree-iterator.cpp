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
class BSTIterator {
public:
    stack<int> s;
    void f(TreeNode* root,stack<int> &s){
        if(root == NULL)
        return;
        f(root->right,s);
        s.push(root->val);
        f(root->left,s);  
    }
    BSTIterator(TreeNode* root) {
        f(root,s);
    }
    int next() {
        int k = s.top();
        s.pop();
        return k; 
    }
    
    bool hasNext() {
        return  !s.empty()?1:0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */