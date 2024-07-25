class Solution {
public:
    void merge(vector<int>& nums,int l, int m, int r){
        vector<int> temp;
        int i=l,j=m+1, k = l;
        while(i<=m && j<=r){
            if(nums[i]>=nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
            else{
                 temp.push_back(nums[i]);
                i++;
            }
        }
        while(i<=m){
            temp.push_back(nums[i]);
                i++;
        }
        while(j<=r){
             temp.push_back(nums[j]);
            j++;
        }
        for(int i=l;i<=r;i++){
            nums[i] = temp[i-l]; 
        }
    }
    void mergesort(vector<int> &nums, int l,int r){
        if(l<r){
            int m = (l+r)/2;
            mergesort(nums,l,m);
            mergesort(nums,m+1,r);
            merge(nums,l,m,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};