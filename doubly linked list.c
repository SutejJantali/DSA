#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;
void create(int a[],int n)
{
    int i;
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
      first->data=a[0];
      first->prev=first->next=NULL;
        last=first;
      for(i=1;i<n;i++)
      {
         t=(struct node *)malloc(sizeof(struct node));
         t->data=a[i];
         t->next=NULL;
         t->prev=last;
         last->next=t;
         last=t;
      }
}
void insert(int ele,int pos)
{
    int i;
    struct node *t,*p=first;
    if(pos==0)
        {
            if(first==NULL)
            {
                first=t;
                first->next=first->prev=NULL;
            }
            t=(struct node *)malloc(sizeof(struct node));
            t->data=ele;
            t->next=first;
            t->prev=NULL;
            first->prev=t;
            first=t;
        }

    else
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=ele;
        for(i=0;i<pos-1;i++)
            p=p->next;
        t->prev=p;
        t->next=p->next;
        if(p->next!=NULL)
            p->next->prev=t;
        p->next=t;
    }
}
int delete(int pos)
{
    int i,x;
    struct node *p=first,*q=NULL;
    if(pos==1)
    {
        first=first->next;
        first->prev=NULL;
        p->next=NULL;
        x=p->data;
        free(p);
        p=first;
        return x;
    }
    else
    {
        for(i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        if(p->next!=NULL)
            p->next->prev=q;
        x=p->data;
        free(p);
        return x;
    }
}
void display(struct node *f)
{
    do
    {
        printf("%d\t",f->data);
        f=f->next;
    }while(f);
}
int main()
{
    int i,choice,ele,pos,n;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    create(a,n);
    printf("enter your choice:\n 1.insert\n2.delete\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("enter the element and position:\n");
                scanf("%d %d",&ele,&pos);
                insert(ele,pos);
                break;
        case 2:printf("enter the position:\n");
                scanf("%d",&pos);
                delete(pos);
                break;
        default:printf("wrong choice\n");
                break;
    }
    display(first);
}
