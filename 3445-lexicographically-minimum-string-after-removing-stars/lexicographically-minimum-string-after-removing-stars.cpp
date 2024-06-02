#define P pair<int, int> 
class Compare {
public:
    bool operator()(P below, P above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    string clearStars(string s) {
        vector<int>idx;
        priority_queue<P, vector<P>, Compare> pq;

        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
               
                idx.push_back( i);
                auto x = pq.top();
                pq.pop();
                idx.push_back( x.second);
            }
            else{
                pq.push({s[i]-'a', i});
            }
        }

        sort( idx.begin(), idx.end());
        for( int i=idx.size()-1;i>=0;i--){
            s.erase( idx[i],1);
        }
        return s;
    }
};