#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

/*
 * 函数名：create_node
 * 功能：创建一个包含指定数据的新节点
 * 参数：int data - 要存储在新节点中的数据
 * 返回值：Node * - 指向新创建节点的指针
 */
Node *create_node(int data)
{
    // 分配内存以创建新的Node实例
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        // 如果内存分配失败，则打印错误信息并终止程序
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // 设置新节点的数据
    new_node->data = data;
    // 将新节点的next指针设置为NULL，表示当前节点没有下一个节点
    new_node->next = NULL;
    // 返回新创建的节点
    return new_node;
}

/**
 * 在链表的末尾添加新节点。
 * 
 * 该函数通过创建一个包含新数据的新节点，并将其附加到链表的末尾来扩展链表。
 * 如果链表为空，新节点将成为链表的头节点。
 * 
 * @param head 链表头指针的指针。用于修改链表的头节点。
 * @param data 要添加到链表的新数据。
 */
void append(Node **head, int data)
{
    // 创建并初始化新节点
    Node *new_node = create_node(data);
    
    // 如果链表为空，将新节点设为头节点
    if (!(*head))
    {
        *head = new_node;
        return;
    }
    
    // 遍历链表直到找到最后一个节点
    Node *current = *head;
    while (current->next)
    {
        current = current->next;
    }
    
    // 将新节点附加到链表末尾
    current->next = new_node;
}

/**
 * 在链表中查找指定数据的节点
 * 
 * 本函数通过遍历链表，搜索与指定数据匹配的节点。如果找到匹配的节点，则返回该节点的指针；
 * 如果未找到匹配的节点，则返回空指针。此函数采用线性搜索的方法，时间复杂度为O(n)，其中n
 * 是链表的长度。
 * 
 * @param head 链表的头节点指针如果链表为空，head也为空指针
 * @param data 要查找的目标数据
 * @return 包含目标数据的节点指针如果找到，则指向该节点；如果未找到，则返回空指针
 */
Node *find(Node *head, int data)
{
    // 从头节点开始，逐一检查每个节点的数据是否与目标数据匹配
    Node *current = head;
    while (current && current->data != data)
    {
        // 如果当前节点的数据与目标数据不匹配，则移动到下一个节点
        current = current->next;
    }
    // 返回找到的节点指针或者空指针
    return current;
}

/**
 * 遍历并打印链表中的所有节点数据。
 * 
 * 本函数接收一个指向链表头节点的指针，通过遍历链表，打印每个节点的数据域内容，
 * 并在末尾打印"None"表示链表结束。这种方式可以帮助理解链表的结构和节点之间的连接方式。
 * 
 * @param head 链表的头节点指针。如果head为NULL，则表示链表为空，函数将不执行任何操作。
 */
void display(Node *head)
{
    // 初始化一个指针，指向当前遍历的节点，初始值为链表头节点
    Node *current = head;
    // 循环遍历链表，直到current指向NULL，表示到达链表末尾
    while (current)
    {
        // 打印当前节点的数据域内容，并添加一个指向符号，表示指向下一个节点
        printf("%d -> ", current->data);
        // 将current指针更新为下一个节点
        current = current->next;
    }
    // 打印链表末尾标识，表示遍历结束
    printf("None\n");
}

int main()
{
    // 创建一个指向链表头的指针，初始值为空
    Node *head = NULL;
    // 向链表末尾追加节点，值为1
    append(&head, 1);
    // 向链表末尾追加节点，值为2
    append(&head, 2);
    // 向链表末尾追加节点，值为3
    append(&head, 3);
    // 显示链表中的所有节点
    display(head);
    // 在链表中查找值为2的节点
    Node *found_node = find(head, 2);
    // 根据查找结果，决定输出的信息
    if (found_node)
    {
        printf("Element %d found in the list.\n", found_node->data);
    }
    else
    {
        printf("Element not found in the list.\n");
    }
    // 返回程序执行结果
    return 0;
}
