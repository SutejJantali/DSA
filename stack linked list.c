#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
        printf("stack overflow\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
void pop()
{
    struct node *p;
    int x=-1;
    if(top==NULL)
        printf("stack is empty\n");

    else
    {
        p=top;
        top=top->next;
        x=p->data;
        free(p);
    }
    return x;
}

int peek(int pos)
{
    int x=-1,i;
    struct node *p=top;
    for(i=0;p!=NULL && i<pos-1;i++)
        p=p->next;

    if(p!=NULL)
        return p->data;
    else
            return -1;
}
int stacktop()
{
    if(top)
        return top->data;
    return -1;
}

int isEmpty()
{
    return top?0:1;
}

int isFull()
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    int r=t?1:0;

    free(t);
    return r;

}
void display()
{
    struct node *p;
    p=top;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
    int main()
    {
        push(10);
        push(20);
        push(30);
        display();
        pop();
        display();
    }
