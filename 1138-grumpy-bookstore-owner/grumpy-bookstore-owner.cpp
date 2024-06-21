class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int total = 0;
        for(int i=0; i<customers.size(); i++) {
            if(i < minutes) total += customers[i];
            else if(grumpy[i] == 0) total+= customers[i];
        }
        int max = total;
        int l = 0, r = minutes;
        while(r < customers.size()) {
            if(grumpy[r] == 1) total += customers[r];
            if(grumpy[l] == 1) total -= customers[l];
            r++;
            l++;
            if(max < total) max = total;
        }
        return max;
    }
};