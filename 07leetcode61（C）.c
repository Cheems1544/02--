/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * 将给定的链表向右旋转k个位置。
 *
 * @param head 链表的头节点指针。
 * @param k 旋转的位置数。
 * @return 旋转后的链表头节点指针。
 */
struct ListNode *rotateRight(struct ListNode *head, int k)
{
    // 检查链表是否为空
    if (head == NULL)
    {
        return NULL;
    }
    // 检查链表是否只有一个节点
    if (head->next == NULL)
    {
        return head;
    }
    // 初始化链表长度为1，并设置移动指针和前驱指针
    int len = 1;
    struct ListNode *pmove = head;
    struct ListNode *pre = head;

    // 遍历链表，计算链表长度
    while (head->next != NULL)
    {
        len++;
        head = head->next;
    }
    // 重新设置头指针为移动指针
    head = pmove;
    // 计算实际需要移动的次数，并移动到相应位置
    for (int i = 0; i < (len - (k % len) - 1); i++)
    {
        head = head->next;
    }
    // 设置移动指针为下一个节点
    pmove = head->next;
    // 移动k次，找到需要调整的节点
    for (int j = 0; j < (k % len); j++)
    {
        pmove = pmove->next;
    }
    // 将移动指针的下一个节点指向头节点，完成环形链表的断开和重新连接
    pmove->next = pre;
    // 设置新的头节点
    pmove = head->next;
    // 断开原链表的连接
    head->next = NULL;
    // 返回新的头节点
    return pmove;
}