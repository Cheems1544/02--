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
 * 在双向链表中的指定节点之后插入一个新节点。
 * 
 * @param prev_node 在其后面插入新节点的节点指针。
 * @param data 新节点中要存储的数据。
 * 
 * 如果prev_node为空，打印错误信息并退出函数。
 * 否则，创建一个新节点，将其链接到prev_node后面，同时将prev_node的下一个节点链接到新节点。
 */
void insert_after(Node *prev_node, int data)
{
    // 检查prev_node是否为空，防止空指针错误
    if (!prev_node)
    {
        printf("The given previous node cannot be NULL.\n");
        return;
    }
    // 创建新节点并初始化其数据
    Node *new_node = create_node(data);
    // 将新节点链接到prev_node后面
    new_node->next = prev_node->next;
    prev_node->next = new_node;
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
    // 创建一个空的链表头指针，用于后续的链表构建
    Node *head = NULL;
    // 向链表中添加三个节点，值分别为1、2、3
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    // 展示链表当前的状态
    display(head);
    // 在链表的第二个节点（即head的下一个节点）之后插入一个新节点，值为4
    insert_after(head->next, 4);
    // 再次展示链表当前的状态，以查看插入操作的效果
    display(head);
    // 返回程序正常执行结束的状态码
    return 0;
}
