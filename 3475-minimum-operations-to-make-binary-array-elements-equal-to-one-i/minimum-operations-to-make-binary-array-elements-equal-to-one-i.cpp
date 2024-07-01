class Solution {
public:
    int k=0;
    void f(vector<int>& nums,int j){
        for(int m=0;m<3;m++){
            nums[j]=(nums[j]==1)?0:1;
            j++;
        }
        k++;
    }
    int minOperations(vector<int>& nums) {
        int i=0,j=0;
        while(j<nums.size()-2){
            if(nums[j]==0){
                f(nums,j);
            }
            j++;
        } 
        if(nums[nums.size()-1]!= 0 && nums[nums.size()-2]!=0)
        return k;
        return -1;
    }
};