/*
���ȷ������ÿ��Ԫ�ض�����ȵĸ�����? �����õ��˸����۵�֪ʶ, �ڱ�������i����ʱ����ѡȡ������ĸ���Ϊ1/i, Ȼ����֤��һ��ÿ������ѡ����
����: ���ڵ�һ�����䱻ѡ��ĸ���Ϊ1/1*(1-1/2)*(1-1/3)*(1-1/4)*...*(1-1/n) = 1/n, ����(1-1/n)����˼�ǲ�ѡ��n�ĸ���, Ҳ����ѡ��1�ĸ��ʳ�
�Բ�ѡ���������ĸ���. ��������һ����i��˵, �䱻ѡ��ĸ���Ϊ1/i*(1-1/(i+1))*...*(1-1/n), ������ÿһ������ʱ������ֻҪ�������һ���Ƿ���i
�ı������ɾ����Ƿ�ȡ��ǰ������.
*/
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        p=head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* n=p;
        int ans=p->val;
        for(int i=1; n!=nullptr; n=n->next, i++){
            if(rand()%i==0) ans=n->val;
        }
        return ans;
    }
private:
    ListNode* p;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
