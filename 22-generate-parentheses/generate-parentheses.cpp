class Solution {
public:
    bool check(string s){
        stack<int> st;
        if(s[0] == ')') return false;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
    void f(int i,int n, vector<string>& ans, string s){
        if(i == 2*n){
            if(check(s))
            ans.push_back(s);
            return ;
        }
        f(i+1,n,ans,s+'(');
        f(i+1,n,ans,s+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        f(0,n,ans,s);
        return ans;
    }
};