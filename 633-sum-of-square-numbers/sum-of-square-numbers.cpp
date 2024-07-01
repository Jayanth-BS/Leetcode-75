
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0,j=sqrt(c);
        while(i<=j){
            long long tot = i*i+j*j;
            if(tot>c)
            j--;
            else if (tot<c)
            i++;
            else
            return 1;
        }
        return 0;
    }
};