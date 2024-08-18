#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义向量结构体
typedef struct vector{
    int size, count;
    int *data;
} vector;

// 创建一个新的向量
vector *getNewVector(int n){
    vector *p = (vector *)malloc(sizeof(vector));
    p->size = n;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int) * n);

    return p;
}

// 扩展向量容量
int expand(vector *v){
    if (v == NULL) return 0;

    printf("expand v from %d to %d\n", v->size, 2 * v->size);

    int *p = (int *)realloc(v->data, sizeof(int) * 2 * v->size);
    if (p == NULL) return 0;
    v->data = p;
    v->size *= 2;

    return 1;
}

// 向向量中插入元素
int insert(vector *v, int pos, int val){
    if (pos < 0 || pos > v->count) return 0;

    if (v->size == v->count && !expand(v)) return 0;

    for (int i = v->count - 1; i >= pos; i--){
        v->data[i + 1] = v->data[i];
    }

    v->data[pos] = val;
    v->count += 1;

    return 1;
}

// 从向量中删除元素
int erase(vector *v, int pos){
    if (pos < 0 || pos >= v->count) return 0;

    for (int i = pos + 1; i < v->count; i++){
        v->data[i - 1] = v->data[i];
    }

    v->count -= 1;

    return 1;
}

// 清空并释放向量
void clear(vector *v){
    if (v == NULL) return ;

    free(v->data);
    free(v);

    return;
}

// 输出向量的内容
void output_vector(vector *v){
    int len = 0;

    printf("\n");

    for (int i = 0; i < v->size; i++){
        len += printf("%3d", i);
    }
    printf("\n");

    for (int i = 0; i < len; i++){
        printf("-");
    }
    printf("\n");

    for (int i = 0; i < v->count; i++){
        printf("%3d", v->data[i]);
    }
    printf("\n");

    return;
}

int main(){
    srand(time(0));
    #define MAX_OP 20

    // 初始化向量
    vector *v = getNewVector(2);

    // 主循环
    for (int i = 0; i < MAX_OP; i++){
        int op = rand() % 3, pos, val, ret;
        switch (op)
        {
        case 0:
            // 保留此处用于扩展操作
            break;
        case 1:
            // 保留此处用于其他操作
            break;
        case 2:
            // 随机选择位置和值进行插入
            pos = rand() % (v->count + 2);
            val = rand() % 100;
            ret = insert(v, pos, val);
            printf("insert %d at %d to vector = %d\n", val, pos, ret);
            break;
        case 3:
            // 随机选择位置进行删除
            pos = rand() % (v->count + 2);
            ret = erase(v, pos);
            printf("erase item at %d in vector = %d\n", pos, ret);
            break;
        }

        // 输出当前向量状态
        output_vector(v);
    }

    // 清理资源
    clear(v);

    return 0;
}