/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 反转链表
// 该函数接收一个链表头指针，并返回反转后的链表头指针
// 参数:
//   head: 链表的头指针，可能为NULL
// 返回值:
//   返回反转后的链表头指针，如果输入为空或只有一个节点，则返回原头指针
struct ListNode *reverseList(struct ListNode *head)
{
    // 定义指针p用于遍历链表
    struct ListNode *p;
    // 定义指针q用于临时存储节点，以便修改节点的next指针
    struct ListNode *q;

    // 如果链表为空或只有一个节点，不需要反转，直接返回原头指针
    if (head == NULL || head->next == NULL)
        return head;

    // 初始化p指向链表的第二个节点
    p = head->next;
    // 将原头节点的next指针置空，作为新链表的尾节点
    head->next = NULL;

    // 循环遍历链表，直到p为空，即遍历到链表末尾
    while (p != NULL)
    {
        // 用q临时存储当前节点，以便修改其next指针
        q = p;
        // 移动p到下一个节点
        p = p->next;
        // 将当前节点的next指针指向前一个节点，实现反转
        q->next = head;
        // 更新head指针，将当前节点作为新链表的头节点
        head = q;
    }
    // 返回反转后的链表头指针
    return head;
}