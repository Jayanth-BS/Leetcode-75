/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
        return false;
        ListNode* slow = head;
        if(head->next == NULL)
        return false;
        ListNode* fast = head->next;
        while(fast!= NULL && fast->next!= NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            return 1;
        }
        return 0;
    }
};