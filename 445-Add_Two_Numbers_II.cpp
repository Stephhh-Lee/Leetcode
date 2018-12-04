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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> sta1;
        stack<int> sta2;
        stack<int> sta;
        while(l1!=nullptr){
            sta1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=nullptr){
            sta2.push(l2->val);
            l2 = l2->next;
        }
        int c = 0;
        while(!sta1.empty() && !sta2.empty()){
            int sum = sta1.top() + sta2.top() + c;
            c = sum/10;
            sum %= 10;
            sta.push(sum);
            sta1.pop();
            sta2.pop();
        }
        if(!sta2.empty()) sta1 = sta2;
        while(!sta1.empty()){
            int sum = sta1.top() + c;
            c = sum/10;
            sum %= 10;
            sta.push(sum);
            sta1.pop();
        }
        if(c == 1) sta.push(1);
        ListNode* dump = new ListNode(0);
        ListNode* ret = dump;
        while(!sta.empty()){
            dump->next = new ListNode((int)sta.top());
            dump = dump->next;
            sta.pop();
        }
        return ret->next;
    }
};
