class Solution {
public:
    bool canplace(vector<int>& p, int k,int m){
        int c=1, last = p[0];
        for(int i = 1;i<p.size();i++){
            if(p[i]-last>=k)
            {c++;
            last = p[i];
            }
        }
        return (c>=m)?1:0;
    }
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        int n=p.size();
        int mid,l =0, h=p[n-1]-p[0];
        while(l<=h){
            mid = (l+h)/2;
            if(canplace(p,mid,m)){
                l = mid+1;
            }
            else
            h = mid-1;
        }
        return h;
    }
};