class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int arr[n];
        for(int i=0;i<n;i++)
        arr[i]=0;
        vector<bool> ans;
        int c=0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]%2 == nums[i]%2 ){
                c++;
                arr[i+1] = c;
            }
            else{
                arr[i+1] = c;
            }
            cout<<arr[i]<<' ';
        }

        for(int i=0;i<queries.size();i++){
            
            if(arr[queries[i][1]]-arr[queries[i][0]]==0)
            ans.push_back(true);
            else
            ans.push_back(false);
        }
return ans;
    }
};