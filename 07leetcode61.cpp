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
     * 计算链表的长度
     * 
     * @param head 链表的头指针
     * @return 返回链表的长度
     */
    int getLenght(ListNode *head)
    {
        // 初始化计数器n为0
        int n = 0;
        
        // 遍历链表，直到head为空
        while (head)
        {
            // 每遍历一个节点，计数器n加1
            n += 1;
            // 移动到下一个节点
            head = head->next;
        }
        // 返回计数器n的值，即链表的长度
        return n;
    }
// 将链表向右旋转k个位置
ListNode *rotateRight(ListNode *head, int k)
{
    // 如果链表为空，直接返回
    if (head == NULL)
        return head;
    
    // 获取链表长度
    int n = getLenght(head);
    
    // 对k进行取模操作，避免不必要的旋转
    k %= n;
    
    // 如果k为0，不需要旋转，直接返回原链表
    if (k == 0)
        return head;
    
    ListNode *p = head, *q = head;
    
    // 将p指针移动到距离链表头部k个位置的地方
    for (int i = 0; i < k; i++)
        p = p->next;
    
    // 如果p到达了链表尾部，说明k大于等于链表长度，直接返回原链表
    while (p)
        p = p->next, q = q->next;
    
    // p现在指向链表的新头部，q指向原链表的尾部
    p = q->next;
    q->next = NULL;
    q = p;
    
    // 将原链表的尾部连接到新链表的头部，形成一个循环链表
    while (q->next != NULL)
        q = q->next;
    
    // 将循环链表闭合
    q->next = head;
    
    // 返回新链表的头部
    return p;
}
};