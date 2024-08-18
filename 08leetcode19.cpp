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
/*
 * 删除链表中倒数第n个节点
 * 
 * @param head 链表的头指针
 * @param n 距离链表末尾的倒数第n个节点
 * @return 删除节点后的链表头指针
 */
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // 初始化两个指针，用于定位待删除节点的前一个节点
    ListNode new_head, *p = &new_head, *q = p;
    // 将新头节点的下一个节点指向原头节点，保持链表的连续性
    new_head.next = head;

    // q指针前进n+1步，找到待删除节点的后一个节点
    for (int i = 0; i <= n; i++)
    {
        q = q->next;
    }

    // p和q指针同时前进，直到q指向链表末尾
    // 此时p指向待删除节点的前一个节点
    while (q)
    {
        p = p->next;
        q = q->next;
    }

    // 跳过待删除节点，将其从链表中移除
    p->next = p->next->next;

    // 返回更新后的链表头指针
    return new_head.next;
}
};