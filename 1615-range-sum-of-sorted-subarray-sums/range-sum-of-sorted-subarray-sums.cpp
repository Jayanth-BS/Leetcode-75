class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++)
            pq.push({nums[i],i});

        int res = 0;
        for(int count = 1;count<=right;count++){
            pair p = pq.top();
            pq.pop();
            int ni = p.second + 1;
            int s = p.first;
            if(count >= left)
                res = (res + s) % 1000000007; 
            if(ni < n){
                int nsum = p.first + nums[ni];
                pq.push({nsum,ni});
            }  
        }
        return res;
    }
};