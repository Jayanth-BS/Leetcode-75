/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        queue<TreeNode*> q;
        TreeNode* temp = root;
        q.push(root);
        while(!q.empty()){
            
            auto i = q.front();
            q.pop();
            if(i != NULL){
                ans += to_string(i->val);   
                ans += "#";
                q.push(i->left);
                q.push(i->right);
            }
            else{
                ans+="null#";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0,j=0;
        queue<TreeNode*> q;
        vector<string> nodes;
        
        while(i < data.size()){
            while(j<data.size() && data[j] != '#')
                j++;
            
            nodes.push_back(data.substr(i,j-i));
            i = j+1;
            j = i;
        }
        
        if(nodes[0] == "null"){
               return nullptr;
            }

            int ind = 1;
            int m = stoi(nodes[0]);
            TreeNode* root  = new TreeNode(m);
            q.push(root);

            while(!q.empty()){
                TreeNode* cur = q.front(); 
                q.pop();
                if(nodes[ind] != "null"){
                    TreeNode* node = new TreeNode(stoi(nodes[ind]));
                    cur->left = node;
                    q.push(node);
                }
                else{
                    cur->left = nullptr;
                }

                ind++;

                if(nodes[ind] != "null"){
                    int m = stoi(nodes[ind]);
                    TreeNode* node = new TreeNode(stoi(nodes[ind]));
                    cur->right = node;
                    q.push(node);
                }
                else{
                    cur->right = nullptr;
                }
                ind++;
            }   
            return root;     
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));