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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode* list, * ans;
        if(node1->val<=node2->val){
            list = node1;
            node1 = node1->next;
        }else{
            list = node2;
            node2 = node2->next;
        }
        ans = list;
        while(node1!=nullptr && node2!=nullptr){
            if(node1->val <= node2->val){
                list->next = node1;
                list = list->next;
                node1=node1->next;
            }
            else{
                list->next = node2;
                list = list->next;
                node2=node2->next;
            }
        }
        if(node1==nullptr) node1 = node2;
        while(node1 != nullptr){
            list->next = node1;
            list = list->next;
            node1=node1->next;
        }
        return ans;
    }
};
