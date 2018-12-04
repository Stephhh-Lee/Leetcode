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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* n = head;
        ListNode* p;
        while(n!= nullptr){
            while(n->next!=nullptr && n->next->val == n->val){
                p = n->next;
                n->next = n->next->next;
                free(p);
            }
            n = n->next;
        }
        return head;
    }
};
