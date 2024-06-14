class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto i: nums)
        pq.push(i);

        while(k!=0){
            int m = pq.top();
            pq.pop();
            pq.push(m+1);
            k--;
        }
        long o= 1;
        while(!pq.empty()){
            o = (o * pq.top())% 1000000007; 
            pq.pop();
        }
        return o;
    }
};