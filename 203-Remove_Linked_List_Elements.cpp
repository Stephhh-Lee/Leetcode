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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        ListNode* node = head;
        while(head && head->val == val) {
            head = head->next;
            free(node);
            node = head;
        }
        //return head;
        while(node != nullptr){
            if(node->next != nullptr)
                if(node->next->val == val){
                //ListNode* p = node->next;
                node->next = node->next->next;
                //free(p);
            }
            if(node->next == nullptr) node = node->next;
            else if(node->next->val != val) node = node->next;
        }
        return head;
    }
};


ListNode* removeElements(ListNode* head, int val) {
    while(head&&head->val==val)
    head=head->next;
    if(head==NULL) return NULL;
    head->next=removeElements(head->next,val);
    return head;
}