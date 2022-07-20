#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int front;
    int size;
    int rear;
    int *Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(sizeof(int)*q->size);
}
void enqueue(struct Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
        printf("queue is full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if((q->front+1)%q->size==q->rear)
        printf("queue is empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    printf("%d\n",x);
}
void display(struct Queue *q)
{
    int i;
    i=q->front+1;
    do
    {
        printf("%d\t",q->Q[i]);
        i=(i+1)%q->size;
    }while(i!=(q->rear+1)%q->size);
    printf("\n");
}
int main()
{
    struct Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    //enqueue(&q,50);
    display(&q);

    dequeue(&q);

    display(&q);
    //enqueue(&q,20);
    return 0;
}
