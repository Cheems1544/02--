#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义向量结构体
typedef struct vector{
    int size, count;
    int *data;
} vector;

/**
 * 创建一个新的向量
 * @param n 向量的初始容量
 * @return 返回新创建的向量指针
 */
vector *getNewVector(int n){
    vector *p = (vector *)malloc(sizeof(vector));
    p->size = n;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int) * n);

    return p;
}

/**
 * 在指定位置插入一个元素
 * @param v 向量指针
 * @param pos 插入位置
 * @param val 插入的值
 * @return 插入成功返回1，否则返回0
 */
int insert(vector *v, int pos, int val){
    if (pos < 0 || pos > v->count){
        return 0;
    }
    
    if (v->size == v->count){
        return 0;
    }

    for (int i = v->count - 1; i >= pos; i--){
        v->data[i + 1] = v->data[i];
    }

    v->data[pos] = val;
    v->count += 1;

    return 1;
}

/**
 * 删除指定位置的元素
 * @param v 向量指针
 * @param pos 删除位置
 * @return 删除成功返回1，否则返回0
 */
int erase(vector *v, int pos){
    if (pos < 0 || pos >= v->count){
        return 0;
    }
    
    for (int i = pos + 1; i < v->count; i++){
        v->data[i - 1] = v->data[i];
    }

    v->count -= 1;

    return 1;
}

/**
 * 清空向量
 * @param v 向量指针
 */
void clear(vector *v){
    if(v == NULL){
        return;
    }

    free(v->data);
    free(v);

    return;
}

/**
 * 打印向量内容
 * @param v 向量指针
 */
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

    return ;
}

    int main(){
    srand(time(0));
    #define MAX_OP 20

    vector *v = getNewVector(MAX_OP);

    for (int i = 0; i < MAX_OP; i++){
        int op = rand() % 3, pos, val;
        switch (op){
        case 0:
            // code
            break;
        case 1:
            // code
            break;
        case 2:
            pos = rand() % (v->count + 2);
            val = rand() % 100;
            printf("insert %d at %d to vector = %d\n",val, pos, insert(v, pos, val));
            break;
        case 3:
            pos = rand() % (v->count + 2);
            printf("erase item at %d in vector = %d\n", pos, erase(v, pos));
            break;
        }

        output_vector(v);
    }
    
    clear(v);

    return 0;
}