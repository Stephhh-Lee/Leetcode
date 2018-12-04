//¿ìÂýÖ¸Õë

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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* fast = head, * slow = head;
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast->next == nullptr) return slow;
            fast = fast->next;
        }
        return slow;
    }
};
