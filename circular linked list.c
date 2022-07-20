#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void create(int a[],int n)
{
    int i;
    struct node *t,*last;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=a[0];
    head->next=head;
    last =head;

    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void insert(int pos,int x)
{
    struct node *t,*p;
    int i;
    if(pos==0)
    {
        t=(struct node *)malloc(sizeof(struct node));

        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            p=head;
            while(p->next!=head)
                p=p->next;

            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else
    {
        p=head;
        for(i==0;i<pos-1;i++)
        p=p->next;

        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
void display(struct node *h)
{
    do
    {
        printf("%d\t",h->data);
        h=h->next;
    }while(h!=head);
    printf("\n");
}
int main()
{
    int n,pos,x;
    printf("enter the number of elements:\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    create(a,n);
    printf("enter the element and its position \n");
    scanf("%d %d",&x,&pos);
    insert(pos,x);
    display(head);
    return 0;
}
