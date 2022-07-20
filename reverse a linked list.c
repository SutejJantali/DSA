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
    for(i=1; i<n; i++)
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
int count(struct node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}
void arrayreversal1(struct node *p)
{
    int *a,i=0;
    struct node *q=p;
    a=(int *)malloc(sizeof(int)*count(p));

    while(q)
    {
        a[i++]=q->data;
        q=q->next;
    }
    q=p;
    i--;
    while(q)
    {
        q->data=a[i--];
        q=q->next;
    }
}
void arrayreversal2(struct node *p)
{
    struct node *q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;

        q->next=r;
    }
    first=q;

}
void arrayreversal3(struct node *q,struct node *p)
{
    if(p)
    {
        arrayreversal3(p,p->next);
        p->next=q;
    }
    else
        first=q;

}

int main()
{
    int a[]= {1,3,5,7,9,11,13,15};
    create(a,8);
    arrayreversal1(first);
    display(first);

    return 0;
}
