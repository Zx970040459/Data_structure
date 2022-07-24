#include "Queue_test1.h"

//练习日期：2022年7月22日
/* 创建结点 */
Node *creatNode(ElemType data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
/* 创建队列 */
Queue *creatQueue()
{
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->frontNode = newQueue->rearNode = NULL;
    newQueue->size = 0;

    return newQueue;
}
/* 入队 */
bool push_Queue(Queue *q,ElemType data)//输入参数：队列，入队数
{
    Node *newNode = creatNode(data);
    if(q->size == 0)
    {
        q->frontNode = q->rearNode = newNode;
    }
    else
    {
        q->rearNode->next = newNode;
        q->rearNode = newNode;
        q->size ++;
    }
}
/* 出队 */
bool pop_Queue(Queue *q)
{
    if(q->size == 0)
    {
        printf("队列为空！\n");
        return false;
    }
    else
    {
        Node *nextNode = q->frontNode->next;
        free(q->frontNode);
        q->frontNode = nextNode;
        q->size--;
    }
}
/* 判空 */
bool isEmpty_Queue(Queue *q)
{
    if(q->size == 0)
    {
        printf("队列为空！\n");
        return true;
    }
    else
    {
        printf("队列不为空！\n");
        return false;
    }
}
/* 输出对头数据 */
int getTop_Queue(Queue *q)
{
    if(q->size == 0)return false;
    else
    {
        return q->frontNode->data;
    }
}
int main()
{
    Queue *myQue = creatQueue();
    push_Queue(myQue,1);//入队
    push_Queue(myQue,2);
    push_Queue(myQue,3);
    push_Queue(myQue,4);
    int d = getTop_Queue(myQue);
    printf("the top data is :%d\n",d);
    while(myQue->size != 0)
    {
        printf("队列中元素值为：%d \n",myQue->frontNode->data);
        pop_Queue(myQue); //出队
    }
    return 0;
}