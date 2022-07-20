#include<stdio.h>
#define size 10
int queue[size],ele,i,front=-1,rear=-1;
void main()
{
    int choice;
    int ch=1;
    while(ch==1)
    {
        printf("enter the choice:\n");
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }

    }
}
int enqueue()
{
    if(rear==size-1)
    {
        printf("queue full");
        return;
    }
    printf("enter the element: ");
    scanf("%d",&ele);
    if(front==-1)
    {
    front=0;
    }
    rear++;
    queue[rear]=ele;
    printf("%d is enqueued\n",ele);
}
int dequeue()
{
    if(front==rear || front==-1)
        printf("queue is empty\n");
    else
    {
        printf("%d is dequeued\n",queue[front]);
        front++;
    }
}
int display()
{
    for(i=front;i<=rear;i++)
        printf("%d\n",queue[i]);
}
