class Solution {
public:
    int numSteps(string s) {
        int c=0;
    while(s.size() != 1){
        if(s.back() == '0'){
             s.pop_back();
        }
        else{
            cout<<'h';
            int i= s.size()-1;
            while(i>=0 && s[i] != '0'){
                s[i] = '0';
                i--;
            }
            if(i == -1){
                s = '1'+s;
            }
            else{
            s[i] = '1';
            }
        }
        c++;
    }
    return c;
    }
};