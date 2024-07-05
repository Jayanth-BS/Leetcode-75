/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vals;
        ListNode* cur = head;
        while(cur!= NULL){
            vals.push_back(cur->val);
            cur = cur->next;
        }
        if(vals.size() <= 2){
            return {-1,-1};
        }
        vector<int> critical;
        for(int i=1;i<vals.size()-1;i++){
            if((vals[i]<vals[i-1] && vals[i]<vals[i+1])||(vals[i]>vals[i-1] && vals[i]>vals[i+1])){
                critical.push_back(i);
                cout<<i<<' ';
            }
        }
        if(critical.size()<= 1){
            return {-1,-1};
        }
        int min = INT_MAX;
        for(int i=1;i<critical.size();i++){
            
            if(critical[i]-critical[i-1]<min){
                min = critical[i]-critical[i-1];
            }
        }
        return {min,critical[critical.size()-1]-critical[0]};
    }
};