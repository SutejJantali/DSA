#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void enqueue(struct queue *q,int x)
{
    if(q->rear==q->size-1)
        printf("queue full\n");
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct queue *q)
{
    int x=-1;
    if(q->front==q->rear)
        printf("queue empty\n");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void display(struct queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        printf("%d\t",q.Q[i]);
    }
}
int main()
{
    int i,x,choice,c=1;
    struct queue q;
    printf("enter the size of queue: ");
    scanf("%d",&q.size);
    q.Q=(int *)malloc((q.size)*sizeof(int));
    q.front=q.rear=-1;

    while(c==1)
    {
    printf("enter your choice:\n1.enqueue\n2.dequeue\n3.display\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:printf("enter the element:\n");
            scanf("%d",&x);
            enqueue(&q,x);
            break;

    case 2:dequeue(&q);
            break;
    case 3:display(q);
            break;
    default:printf("wrong choice:\n");
            break;
    }
    printf("\nwant to continue? 1-y 0-n\n");
    scanf("%d",&c);
    }

    return 0;
}
