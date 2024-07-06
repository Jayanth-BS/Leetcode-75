class Solution {
public:
    int passThePillow(int n, int time) {
        int k = n;
        n=1;
        while(time!= 0){
                while(n!=k && time){
                    time--;
                    n++;
                    if(time == 0)
                    return n;
                }
                while(n!=1 && time){
                    time--;
                    n--;
                    if(time == 0)
                    return n;
                }
        }
        return n;
    }
};