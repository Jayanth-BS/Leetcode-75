class Solution {
public:
    void f(int tot,int open,int close, vector<string>& ans, string s){
        if(s.size() == tot){
            ans.push_back(s);
            return;
        }
        if(open>close){
            f(tot,open,close+1,ans,s+')');
            if(open<tot/2){
                f(tot,open+1,close, ans,s+'(');
            }
        }
        else{
        f(tot,open+1,close,ans,s+'(');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(2*n,0,0,ans,"");
        return ans;
    }
};