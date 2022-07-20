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
void sortInsert(struct node *p,int x)
{
    int i;
   struct node *t,*q=NULL;
   t=(struct node *)malloc(sizeof(struct node));
   t->data=x;
   t->next=NULL;
   if(first==NULL)
    first=t;
   else
   {
   while(p && x>p->data)
    {
        q=p;
        p=p->next;
    }
    if(p==first)
    {
        t->next=first;
        first=t;
    }
    else
    {
        t->next=q->next;
        q->next=t;
        }
    }
}
int main()
{
    int a[]= {3,5,7,10,15,18,21};
    create(a,7);
    sortInsert(first,20);
    display(first);
        return 0;
}
