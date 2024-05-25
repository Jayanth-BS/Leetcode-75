class Solution {
public:
int ans=0;
    void f(int t, int x){
        if(t == 1)
       { 
        return;
       }
        if(x>0 && t%2==0){
            ans++;
            f(t/2,x-1);
        }
        else
       { ans++;
       if(x==0)
        ans=ans+t-2;
        else
        f(t-1,x);
       }
    
    }

    int minMoves(int t, int x) {
        f(t,x);
        return ans;
    }
};