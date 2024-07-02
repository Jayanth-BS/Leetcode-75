class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int maxi =0;
        int n = heights.size();
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                width = i;
                else
                width = i-st.top()-1;
                maxi = max(maxi,width*height);
            }
            st.push(i);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> height(matrix[0].size(),0);
        int mx = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == '1')
                height[j]++;
                else
                height[j]=0;
            }
             int area = largestRectangleArea(height);
                mx = max(mx,area);
        }
        return mx;
    }
};