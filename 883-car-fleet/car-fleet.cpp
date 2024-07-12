class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<vector<double>> pq;
        for(int i=0;i<position.size();i++){
            double time = (target-(double)position[i])/(double)speed[i];
            pq.push({(double)position[i],(double)speed[i],time});
        }
        int fleet =0;
        while(pq.size()!=1){
            auto ahead = pq.top();pq.pop();
            auto behind = pq.top();pq.pop();
            if(ahead[2]>= behind[2]){
                pq.push({ahead});
            }
            else{
                fleet++;
                pq.push({behind});
            }
        }
        return fleet+1;
    }
};