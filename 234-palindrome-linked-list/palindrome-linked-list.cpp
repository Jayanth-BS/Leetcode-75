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
    ListNode* reve(ListNode* h){
        ListNode* prev = NULL;
        ListNode* cur = h;
        while(cur!= NULL){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast!= NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* rev = reve(slow->next);
        slow->next = NULL;
        while(rev != NULL){
            if(rev->val != head->val){
                return false;
            }
           head = head->next;
           rev = rev->next;
        }
        return 1;
    }
};