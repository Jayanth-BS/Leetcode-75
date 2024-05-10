/**
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head)
        return NULL;

        vector<int> arr;
        ListNode *cur = head;
        while(cur!= NULL){
            arr.push_back(cur->val);
            cur = cur->next;
        }

        
        for(int i =0;i<arr.size();i++){
            int sum = 0;
            for(int j=i;j<arr.size();j++){
                sum += arr[j];
                if(sum  == 0){
                    arr.erase(arr.begin()+i,arr.begin()+j+1);
                    i--;
                    break;
                }
            }
        }

        ListNode* head1 = new ListNode(0);
        cur = head1;
        for(int i=0;i<arr.size();i++)
        {
            ListNode* node = new ListNode(arr[i]); 
            cur->next = node;
            cur = cur->next;
        }
        return head1->next;
    }
};
