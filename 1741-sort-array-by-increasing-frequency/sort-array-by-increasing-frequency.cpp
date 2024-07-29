class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> freq;
        for(auto i: nums){
            freq[i]++;
        }

        auto comp = [&freq](int a, int b) {
            // Sort by frequency in ascending order
            // If frequencies are the same, sort by value in descending order
            if (freq[a] == freq[b]) {
                return a > b;
            }
            return freq[a] < freq[b];
        };

        // Step 3: Sort the nums vector with the custom comparator
        std::sort(nums.begin(), nums.end(), comp);
        return nums;
    }
};