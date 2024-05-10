// For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

// Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<float,vector<float>> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                float m = (float)arr[i]/arr[j];
                if(pq.size()<k){
                    pq.push(m);
                }
                else{
                    if(pq.top()>=m){
                        pq.pop();
                        pq.push(m);
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                float m = (float)arr[i]/arr[j];
                if(m == pq.top()){
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                return ans;
                }
            }
        }
    return ans;
    }
};
