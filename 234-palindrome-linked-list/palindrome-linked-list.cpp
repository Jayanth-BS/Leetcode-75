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
    bool isPalindrome(ListNode* head){
        vector<int> l1;
        ListNode* cur = head;
        while(cur!= NULL){
            l1.push_back(cur->val);
            cur = cur->next;
        }
        vector<int> l2 = l1;
        reverse(l1.begin(),l1.end());
        return l1 ==l2;
    }
};