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
        ListNode* fast = head, * slow = head;
        while(fast != nullptr && slow != nullptr){
            fast = fast->next;
            if(fast != nullptr) fast = fast->next;
            else return false;
            slow = slow->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
