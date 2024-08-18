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
 * 反转链表中的一部分节点。
 * 
 * 本函数主要解决的问题是在给定的链表中，根据指定的起始位置和结束位置，反转这部分的节点。
 * 如果起始位置和结束位置相同，即只有一个节点需要反转，那么直接返回原链表头节点。
 * 如果起始位置不是链表的头部，递归调用函数处理子链表。
 * 如果起始位置是链表的头部，递归调用函数处理除头部以外的子链表，然后反转头部和子链表之间的节点。
 * 
 * @param head 链表的头节点指针。
 * @param left 反转部分的起始位置。
 * @param right 反转部分的结束位置。
 * @return 反转后的链表的头节点指针。
 */
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    // 如果起始位置和结束位置相同，直接返回原链表头节点
    if (left == 1 && right == 1)
    {
        return head;
    }
    // 如果起始位置不是链表的头部，递归调用函数处理子链表
    if (left != 1)
    {
        head->next = reverseBetween(head->next, left - 1, right - 1);
    }
    else
    {
        // 定义尾节点和新的头节点指针
        ListNode *tail = head->next, *new_head;
        // 递归调用函数处理除头部以外的子链表
        new_head = reverseBetween(head->next, left, right - 1);
        // 反转头部和子链表之间的节点
        head->next = tail->next;
        tail->next = head;
        head = new_head;
    }
    // 返回反转后的链表头节点
    return head;
}
};
