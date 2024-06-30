class Solution {
public:
    bool isprime(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)
            return false;
        }
        return true;
    }
    int countPrimes(int n) {
        vector<int> v(n,0);
        for(int i=2;i<sqrt(n);i++){
            for(int j= i*i;j<n;j+=i){
                if(v[j]!=1){
                    v[j]=1;
                }
            }
        }

        int c=0;//O(n.sqrt(n))---->Q(n.1)(seive of e)
        for(int i=2;i<n;i++){
           if(v[i]==0)
           {
            c++;
           }
        }
        return c;
    }
};