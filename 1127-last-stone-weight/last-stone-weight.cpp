class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 2)
        {
            if(stones[0] != stones[1])
            return abs(stones[0]-stones[1]);
            return 0;
        }
        priority_queue<int,vector<int>> pq;
        for(auto i: stones)
        pq.push(i);
    while(pq.size()!= 1){
        if(pq.size() == 0)
        return 0;
        int x = pq.top();
        pq.pop();
        int y =pq.top();
        pq.pop();
        if(x != y){
            pq.push(abs(y-x));
        }
    }
    return pq.top();
    }
};