class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        int i=1;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size() != 1){
            if(i<k){
                int k = q.front();
                q.pop();
                q.push(k);
                i++;
            }
            else if(i == k){
                q.pop();
                i=1;
            }
        }
        return q.front();
    }
};