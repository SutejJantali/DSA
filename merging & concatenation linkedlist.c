#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create1(int a[],int n)
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
void create2(int b[],int n)
{
    int i;
    struct node *t,*last;
    second=(struct node *)malloc(sizeof(struct node));
    second->data=b[0];
    second->next=NULL;
    last=second;
    for(i=1; i<n; i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=b[i];
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
void concatenate(struct node *p,struct node *q)
{
    p=first;
    while(p->next!=0)
    {
        p=p->next;
    }
    p->next=second;
}

void merge(struct node *p,struct node *q)
{
    struct node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL)
        last->next=p;
    else
        last->next=q;
}

int main()
{
    int a[]= {1,3,5,7,9,11,13,15};
    int b[]= {0,2,4,6,8,10,12,16};
    create1(a,8);
    create2(b,8);


    printf("first:\n");
    display(first);
    printf("\nsecond:\n");
    display(second);
    printf("\nconcatenation:\n");
   // concatenate(first,second);
   // display(first);

    printf("\nsorted merge:\n");
    merge(first,second);
    display(third);
    return 0;
}
