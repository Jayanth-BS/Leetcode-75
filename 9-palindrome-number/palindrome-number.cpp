class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        stack<int> st;
        int m=x,r;
        while(m != 0){
            r = m%10;
            m = m/10;
            st.push(r);
        }
        m=x;
        while(m!=0){
            r = m%10;
            m = m/10;
            if(r!= st.top())
            return 0;
            st.pop();
        }
        return 1;
    }
};