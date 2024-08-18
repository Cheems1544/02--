/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
 * 检测并返回链表中的环形节点
 * 
 * 参数:
 * head - 链表的头节点
 * 
 * 返回值:
 * 如果链表中含有环，则返回环的起始节点；否则返回NULL
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    // 初始化两个指针，first用于大步前进，slow用于小步前进
    struct ListNode *first, *slow;
    first = slow = head;

    // 循环条件：first指针及其下一个节点不为空，防止遍历到链表末尾
    while (first && first->next)
    {
        // 慢指针每次前进一步
        slow = slow->next;
        // 快指针每次前进两步
        first = first->next->next;
        // 如果慢指针和快指针相遇，则说明链表有环
        if (slow == first)
        {
            // meet用于记录相遇点
            struct ListNode *meet = slow;
            // 从相遇点和头节点同时出发，每次前进一步，直到它们再次相遇
            while (meet != head)
            {
                head = head->next;
                meet = meet->next;
            }
            // 返回环的起始节点
            return meet;
        }
    }
    // 如果没有相遇，说明链表没有环，返回NULL
    return NULL;
}