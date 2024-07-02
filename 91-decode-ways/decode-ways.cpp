class Solution {
public:
    int t[101];
    int f(int i,int n,string &s){
        if(t[i]!= -1)
        return t[i];
        if(i == n)///one way done
        return 1;
        
        if(s[i]=='0')
        return 0;


        int res = f(i+1,n,s);
        if(i+1<n)
        if(s[i]=='1' || s[i]=='2' && s[i+1]<='6'){
            res += f(i+2,n,s);
        }
        return t[i] = res;
    }
    int numDecodings(string s) {
        memset(t,-1,sizeof(t));
        return f(0,s.size(),s);
    }
};