/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * 反转链表
 * 
 * @param head 链表的头指针
 * @return 反转后链表的新头指针
 */
struct ListNode *reverseList(struct ListNode *head)
{
    // 当链表为空或只有一个节点时，直接返回该链表
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // 定义tail指针指向当前头节点的下一个节点
    struct ListNode *tail = head->next;
    // 递归调用reverseList反转链表的剩余部分，得到新的头指针
    struct ListNode *new_head = reverseList(head->next);
    // 将当前头节点的next指针指向之前的tail，实现节点反转
    tail->next = head;
    // 返回反转后链表的新头指针
    return new_head;
}