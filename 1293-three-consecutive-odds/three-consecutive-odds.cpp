class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i=0,j=0;
        while(i<=j && j<arr.size()){
            if(arr[j]%2==0){
                if(j-i  >= 3)
                return 1;
                i = j+1;
                // cout<<arr[i]<<' ';
            }
            j++;
            if(j == arr.size()){
                 if(j-i  >= 3)
                return 1;
            }
        }
        return 0;
    }
};