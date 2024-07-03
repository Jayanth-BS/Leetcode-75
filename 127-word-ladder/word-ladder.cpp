class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        set<string> s;
        for(auto i: wordList){
            s.insert(i);
        }
        q.push({beginWord,1});
        while(!q.empty()){
            string str = q.front().first;
            int step = q.front().second;
            q.pop();
            if(str == endWord)
            return step;
            for(int i=0;i<str.size();i++){
                char org = str[i];
                for(char ch = 'a';ch<='z';ch++){
                    str[i] = ch;
                    if(s.count(str))
                    {
                        s.erase(str);
                        q.push({str,step+1});
                    }
                }
                str[i]=org;
            }
        }
        return 0;
    }
};