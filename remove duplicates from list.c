#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first=NULL;

void create(int a[],int n)
{
    int i;
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void removeduplicate(struct node *p)
{
    struct node *q=first->next;
    while(q)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
void display(struct node *p)
{
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}
int main()
{
    int a[]={7,7};
    create(a,2);
    removeduplicate(first);
    display(first);

    return 0;
}
