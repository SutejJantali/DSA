#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int *next;
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
struct node *lsearch(struct node *p,int key)
{
    while(p)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}
struct node *rsearch(struct node *p,int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return rsearch(p->next,key);
};

int main()
{
    struct node *p;
    int a[]= {3,5,7,10,15,18,2};
    create(a,7);

    p=rsearch(first,0);
    if(p)
    printf("search element present is: %d \n",p->data);
    else
    printf("key not found\n");

}
