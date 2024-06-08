class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int i=0, sum=0;
        while(sum<target){
            sum+= i;
            i++;
        }

        while((sum-target)%2!=0){
            sum -= 2*abs(sum-target);
            sum+=i;
            i++;
        }
        return i-1;
    }
};