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
 * @brief 反转链表
 * 
 * 递归地反转链表，使原链表的尾部成为新链表的头部。
 * 
 * @param head 原链表的头指针
 * @return ListNode* 返回新链表的头指针
 */
ListNode *reverseList(ListNode *head)
{
    // 如果链表为空或只有一个节点，则直接返回该节点，无需反转
    if (head == NULL || head->next == NULL)
        return head;
    
    // 获取当前头节点的下一个节点，为反转后的链表的尾节点
    ListNode *tail = head->next;
    
    // 递归调用反转函数，返回反转后的链表的头指针
    ListNode *new_head = reverseList(head->next);
    
    // 当前头节点的下一个节点指向原链表的下一个节点的下一个节点，完成反转
    head->next = tail->next;
    
    // 原链表的下一个节点指向当前头节点，完成反转
    tail->next = head;
    
    // 返回反转后的链表的头指针
    return new_head;
}
};