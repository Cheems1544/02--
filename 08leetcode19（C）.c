/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 删除链表中倒数第 n 个节点
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    // 创建一个哨兵节点(dummy node)，以便处理头节点被删除的情况
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *front = dummy;
    struct ListNode *rear = dummy;

    // 前指针先走 n 步
    for (int i = 0; i <= n; i++)
    {
        front = front->next;
    }

    // 前后指针一起走，直到前指针到达链表的末尾
    while (front != NULL)
    {
        front = front->next;
        rear = rear->next;
    }

    // 此时后指针的下一个节点就是要删除的节点
    struct ListNode *toDelete = rear->next;
    rear->next = rear->next->next;

    // 释放要删除的节点的内存
    free(toDelete);

    // 返回新的头节点
    struct ListNode *newHead = dummy->next;
    free(dummy);
    return newHead;
}