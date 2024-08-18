/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    /**
     * 检测并返回单链表中的环形节点
     * 
     * @param head 链表的头指针
     * @return 环的起始节点指针，如果没有环则返回NULL
     */
    ListNode *detectCycle(ListNode *head)
    {
        // 初始化两个指针，p和q，都指向头节点
        ListNode *p = head, *q = head;
        // 使用快慢指针原理，q走两步，p走一步，如果有环，两个指针最终会相遇
        while (q && q->next)
        {
            p = p->next;
            q = q->next->next;
            if (p == q)
                break;
        }
        // 如果q或q的下一个节点为空，说明没有环
        if (q == NULL || q->next == NULL)
            return NULL;
        // 重新定位p指针到头节点
        p = head;
        // 再次遍历链表，这次p和q每次各走一步，直到它们相遇
        while (p != q)
            p = p->next, q = q->next;
        // 返回环的起始节点指针
        return p;
    }
};
