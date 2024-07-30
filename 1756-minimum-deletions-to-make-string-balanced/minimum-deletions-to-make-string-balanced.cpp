class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int c=0;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            
            if(!st.empty() && (st.top() == 'b' && s[i] == 'a')){
                    st.pop();
                    c++;
                }
                else
                st.push(s[i]);
        }
        return c;
    }
};