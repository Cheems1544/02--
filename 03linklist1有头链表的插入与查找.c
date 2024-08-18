#include <stdio.h> // 包含标准输入输出头文件
#include <stdlib.h> // 包含标准库头文件，用于 malloc 和 free
#include <time.h> // 包含时间处理头文件，用于 srand 和 rand

// 定义常量 DL 为 3，用于控制输出格式
#define DL 3
// 定义宏 STR 将传入的参数转换为字符串
#define STR(n) #n
// 定义宏 XSTR 用于解决二次宏展开问题
#define XSTR(n) STR(n)
// 定义宏 DIGIT_LEN_STR 用于生成输出格式字符串
#define DIGIT_LEN_STR(n) "%" XSTR(n) "d"

// 定义链表节点结构体
typedef struct Node
{
    int data; // 节点数据
    struct Node *next; // 指向下一个节点的指针
} Node;

// 创建新节点并初始化
Node *getNewNode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node)); // 分配内存
    p->data = val; // 设置节点数据
    p->next = NULL; // 初始化 next 指针为 NULL
    return p; // 返回新创建的节点
}

// 在指定位置插入新节点
Node *insert(Node *head, int pos, int val)
{
    Node new_head, *p = &new_head, *node = getNewNode(val); // 创建临时节点和新节点
    new_head.next = head; // 设置临时节点指向原链表头
    for (int i = 0; i < pos; i++) // 循环到插入位置
        p = p->next;
    node->next = p->next; // 新节点指向当前位置的下一个节点
    p->next = node; // 当前位置指向新节点
    return new_head.next; // 返回新的链表头
}

// 清空链表
void clear(Node *head)
{
    if (head == NULL)
        return; // 如果链表为空则直接返回
    for (Node *p = head, *q; p; p = q) // 遍历链表
    {
        q = p->next; // 保存下一个节点
        free(p); // 释放当前节点内存
    }
}

// 输出链表
void output_linklist(Node *head)
{
    int n = 0; // 计数器
    for (Node *p = head; p; p = p->next) // 统计链表长度
        n += 1;
    for (int i = 0; i < n; i++) // 输出索引
    {
        printf(DIGIT_LEN_STR(DL), i); // 输出索引数字
        printf("  "); // 输出间隔
    }
    printf("\n"); // 换行
    for (Node *p = head; p; p = p->next) // 输出数据
    {
        printf(DIGIT_LEN_STR(DL), p->data); // 输出数据数字
        printf("->"); // 输出箭头
    }
    printf("\n\n"); // 换行并输出空行
}

// 查找链表中的值
int find(Node *head, int val)
{
    Node *p = head; // 初始化指针
    int n = 0; // 计数器
    while (p) // 遍历链表
    {
        if (p->data == val) // 如果找到值
        {
            output_linklist(head); // 输出链表
            int len = n * (DL + 2) + 2; // 计算指示符的位置
            for (int i = 0; i < len; i++) // 输出空格
                printf(" ");
            printf("^\n"); // 输出指示符
            for (int i = 0; i < len; i++) // 输出空格
                printf(" ");
            printf("|\n"); // 输出指示符
            return 1; // 返回成功标志
        }
        n += 1; // 更新计数器
        p = p->next; // 移动指针
    }
    return 0; // 返回失败标志
}

// 主函数
int main()
{
    srand(time(0)); // 初始化随机种子
#define MAX_OP 7 // 定义最大操作次数
    Node *head = NULL; // 初始化链表头为空
    for (int i = 0; i < MAX_OP; i++) // 执行多次插入操作
    {
        int pos = rand() % (i + 1), val = rand() % 100; // 生成随机位置和值
        printf("insert %d at %d to linklist\n", val, pos); // 输出插入信息
        head = insert(head, pos, val); // 插入新节点
        output_linklist(head); // 输出更新后的链表
    }
    int val; // 读取用户输入的值
    while (~scanf("%d", &val)) // 读取整数直到遇到 EOF
    {
        if (!find(head, val)) // 如果未找到值
        {
            printf("not found\n"); // 输出提示
        }
    }
    clear(head); // 清空链表
    return 0; // 正常退出
}