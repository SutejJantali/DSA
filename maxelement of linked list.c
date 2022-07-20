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
int main()
{
    int a[]= {3,5,7,10,15,18,2};
    create(a,7);
    printf("max element is: %d",max(first));
    return 0;
}
