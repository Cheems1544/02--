#include <stdio.h> // 包含标准输入输出头文件
#include <stdlib.h> // 包含标准库头文件，用于 malloc 和 free

/*
功能解释：
定义链表节点 (struct Node):

data: 存储每个节点的数据。
next: 指向链表中的下一个节点。
创建新节点 (create_node):

使用 malloc 分配内存来创建一个新的节点。
初始化节点的数据和指针。
如果内存分配失败，则输出错误信息并终止程序。
在链表末尾添加节点 (append):

创建一个新节点。
如果链表为空，则将新节点设置为链表头。
否则，遍历链表直到最后一个节点，并将新节点连接到最后一个节点之后。
显示链表 (display):

遍历整个链表并打印每个节点的数据。
在链表结束时输出 None 来表示链表的结尾。
主函数 (main):

初始化链表为空。
使用 append 函数向链表添加三个节点。
使用 display 函数显示链表的内容。
程序正常退出
*/

// 定义链表节点结构体
typedef struct Node
{
    int data;          // 节点存储的数据
    struct Node *next; // 指向下一个节点的指针
} Node;

// 创建新节点并初始化
Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node)); // 分配内存
    if (!new_node) // 如果内存分配失败
    {
        printf("Memory allocation failed.\n"); // 输出错误信息
        exit(1); // 终止程序
    }
    new_node->data = data; // 设置节点数据
    new_node->next = NULL; // 初始化 next 指针为 NULL
    return new_node; // 返回新创建的节点
}

// 在链表末尾添加新节点
void append(Node **head, int data)
{
    Node *new_node = create_node(data); // 创建新节点
    if (!(*head)) // 如果链表为空
    {
        *head = new_node; // 设置新节点为链表头
        return; // 直接返回
    }
    Node *current = *head; // 初始化当前节点为链表头
    while (current->next) // 遍历链表直到最后一个节点
    {
        current = current->next; // 移动到下一个节点
    }
    current->next = new_node; // 将新节点连接到最后一个节点之后
}

// 显示链表的内容
void display(Node *head)
{
    Node *current = head; // 初始化当前节点为链表头
    while (current) // 遍历链表
    {
        printf("%d -> ", current->data); // 输出当前节点的数据
        current = current->next; // 移动到下一个节点
    }
    printf("None\n"); // 输出链表结束标志
}

// 主函数
int main()
{
    Node *head = NULL; // 初始化链表头为空
    append(&head, 1); // 添加节点 1 到链表
    append(&head, 2); // 添加节点 2 到链表
    append(&head, 3); // 添加节点 3 到链表
    display(head); // 显示链表
    return 0; // 正常退出
}