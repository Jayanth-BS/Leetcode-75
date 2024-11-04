class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char> q1,q2;
        int c=0;
        for(auto i: goal){
            q1.push(i);
        }
        for(auto j:s){
            q2.push(j);
        }
        while(1){
            if(q1 == q2){
                return 1;
            }
            if(c >= q2.size())
            break;
            char m = q2.front();
            q2.pop();
            q2.push(m);
            c++;
        }
        return 0;
    }
};