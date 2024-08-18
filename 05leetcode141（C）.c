/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * 检查链表中是否存在循环
 * 
 * @param head 链表的头节点指针
 * @return bool 返回true表示链表中存在循环，返回false表示链表中不存在循环
 */
bool hasCycle(struct ListNode *head)
{
    // 如果链表为空或只有一个节点，则认为没有循环
    if (head == NULL || head->next == NULL)
        return false;

    // 初始化慢指针和快指针，分别指向头节点和头节点的下一个节点
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;

    // 遍历链表，直到快慢指针相遇或者快指针无法继续前进
    while (slow != fast)
    {
        // 如果快指针或其下一个节点为空，则认为没有循环
        if (fast == NULL || fast->next == NULL)
            return false;

        // 慢指针每次移动一个节点
        slow = slow->next;
        // 快指针每次移动两个节点
        fast = fast->next->next;
    }

    // 如果快慢指针相遇，则表示链表中存在循环
    return true;
}