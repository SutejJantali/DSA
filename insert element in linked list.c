#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int *next;
}*first=NULL;
void create(int a[],int n)
{
    int i,count=1;
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
        count++;
    }
}
void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}
int max(struct node *p)
{
    int m=-32767;
    while(p)
    {
        if(p->data>m)
            m=p->data;
        p=p->next;

    }
    return m;
}
void insert(struct node *p,int pos,int x)
{
    int i;
   struct node *t;
    if(pos<0)
        return 0;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    if(pos==0)
    {
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        p=first;
        for(i=0;i<pos-1 && p;i++)
            p=p->next;
        if(p)
        {
            t->next=p->next;
            p->next=t;
        }
    }
}
int main()
{
    int a[]= {3,5,7,10,15,18,2};
    create(a,7);
    insert(first,5,20);
    display(first);
        return 0;
}
