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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len=0;
        vector<ListNode*> ans;
        ListNode* head = root;
        while(head!=nullptr){
            head=head->next;
            len++;
        }
        head=root;
        if(len<k){
            int i=0;
            while(head!=nullptr){
                ListNode* node = head;
                head=head->next;
                node->next=nullptr;
                ans.push_back(node);
                i++;
            }
            while(i<k){
                ans.push_back(nullptr);
                i++;
            }
        }
        else{
            int remainder = len % k;
            int quotient = len / k;
            int i = 0;
            while(i<remainder){
                ListNode* node = head;
                ans.push_back(node);
                int j=0;
                while(j<quotient+1){
                    node = head;
                    head = head->next;
                    j++;
                }
                node->next = nullptr;
                i++;
            }
            
            while(i<k){
                ListNode* node = head;
                ans.push_back(node);
                int j=0;
                while(j<quotient){
                    node = head;
                    head = head->next;
                    j++;
                }
                node->next = nullptr;
                i++;
            }
            
        }
        return ans;
    }
};
