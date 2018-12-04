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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow;
        ListNode* pre;
        while(n--){
            fast=fast->next;
        }
        slow = head;
        while(fast != nullptr){
            pre=slow;
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==head){
            head=head->next;
            free(slow);
            return head;
        }
        pre->next=slow->next;
        free(slow);
        //if(slow==head) head=slow->next;
        return head;
    }
};