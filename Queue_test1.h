#ifndef __QUE__
#define __QUE__
/* 库函数 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 宏定义 */
#define true 1
#define false 0
#define bool char
/* 结构体相关 */
typedef int ElemType;
/* 定义结点类型结构体 */
typedef struct Node
{
    struct Node *next;
    ElemType data;
}Node;
/* 定义队列类型结构体 */
typedef struct q
{
    Node *frontNode;//头结点
    Node *rearNode; //尾结点
    int size; //定义队列长度
}Queue;

/* 创建结点 */
Node *creatNode(ElemType data);
/* 创建队列 */
Queue *creatQueue();
/* 入队 */
bool push_Queue(Queue *q,ElemType data);//输入参数：队列，入队数据
/* 出队 */
bool pop_Queue(Queue *q);
/* 判空 */
bool isEmpty_Queue(Queue *q);
/* 输出对头数据 */
int getTop_Queue(Queue *q);


#endif