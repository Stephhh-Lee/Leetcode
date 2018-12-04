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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int,int> m;
        for(int i=0; i<G.size(); i++){
            m[G[i]]=0;
        }
        int ans=0;
        int counter = 1;
        bool tmp = false, pretmp;
        while(head!=nullptr){
            pretmp = tmp;
            if(m.find(head->val) != m.end()) tmp = true;
            else tmp = false;
            if(tmp && ! pretmp){
                ans++;
            }
            head=head->next;
        }
        return ans;
    }
};
