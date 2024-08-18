/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    /**
     * 反转一个单链表
     * 
     * @param head 链表的头指针
     * @return 反转后链表的新头指针
     */
    ListNode *reverseList(ListNode *head)
    {
        // 创建一个哨兵节点作为新链表的头指针
        ListNode new_head, *p = head, *q;
        // 初始化哨兵节点的next指针为NULL
        new_head.next = NULL;

        // 遍历原链表，直到p为空，即原链表所有节点已被反转
        while(p)
        {
            // 临时保存p的下一个节点，以便后续操作
            q = p->next;
            // 将p的next指针指向新链表的头节点的next，实现节点反转
            p->next = new_head.next;
            // 更新新链表的头节点的next指针，指向当前反转节点p
            new_head.next = p;
            // 移动到下一个待反转节点
            p = q;
        }
        // 返回新链表的头节点
        return new_head.next;
    }
};