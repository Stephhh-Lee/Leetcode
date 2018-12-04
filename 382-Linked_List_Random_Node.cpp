/*
如何确保对于每个元素都有相等的概率呢? 这里用到了概率论的知识, 在遍历到第i个数时设置选取这个数的概率为1/i, 然后来证明一下每个数被选到的
概率: 对于第一个数其被选择的概率为1/1*(1-1/2)*(1-1/3)*(1-1/4)*...*(1-1/n) = 1/n, 其中(1-1/n)的意思是不选择n的概率, 也就是选择1的概率乘
以不选择其他数的概率. 对于任意一个数i来说, 其被选择的概率为1/i*(1-1/(i+1))*...*(1-1/n), 所以在每一个数的时候我们只要按照随机一个是否是i
的倍数即可决定是否取当前数即可.
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
