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
     * 检测链表中是否有环
     * 使用快慢指针的方法，如果两个指针最终相遇，则说明链表有环
     * 
     * @param head 链表的头指针
     * @return bool 返回true表示链表有环，返回false表示链表无环
     */
    bool hasCycle(ListNode *head)
    {
        // 初始化快慢指针
        ListNode *p = head, *q = head;
        // 循环条件：快指针及其下一个节点非空
        while(q && q->next)
        {
            // 慢指针每次移动一步
            p = p->next;
            // 快指针每次移动两步
            q = q->next->next;
            // 如果快慢指针相遇，说明有环
            if(p == q)
            {
                return true;
            }
        }
        // 如果循环结束仍未相遇，说明无环
        return false;
    }
};