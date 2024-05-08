// You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

// Return the head of the linked list after doubling it.
// /**
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
    ListNode* doubleIt(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* head1 = new ListNode(1);
        int h =  head->val;
        if(h>4)    
            head1->next = head;
    
        while(cur!= nullptr){
            int x = cur->val;
            x = x*2;
            if(x/10 && prev != NULL){
                prev->val += 1; 
            }
            cur->val = x%10; 
            prev = cur;
            cur = cur->next;
        }
        return (h > 4)?head1:head;
    }
};
