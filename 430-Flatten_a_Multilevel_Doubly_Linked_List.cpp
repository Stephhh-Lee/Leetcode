//**********************************
//ÓĞµãÄÑ
//**********************************
class Solution {
public:
    Node* getFlatten(Node* head){
        Node* curr = head;
        Node* save;
        while(head){
            save = head->next;
            if(head->child){
                Node* temp = head->next;
                head->next = head->child;
                head->child->prev = head;
                head->child = NULL;
                temp = getFlatten(head->next);
                if(temp&&save){
                    temp->next = save;
                    save->prev = temp;
                }
            }
            if(!save) break;
            head = save;
        }
        return head;
    }
    Node* flatten(Node* head) {
        Node* ans = head;
        getFlatten(head);
        return ans;
    }
};
