#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};
void create(struct stack *st,int size)
{
    st->size=size;
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}
void push(struct stack *st,int p)
{
    if(st->top==st->size-1)
        printf("stack full");
    else
    {
        st->top++;
        st->s[st->top]=p;
    }
}
int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
        printf("stack empty");
    else
    {
        x=st->s[st->top--];
    }
    return x;

}
int isEmpty(struct stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}
int stackTop(struct stack st)
{
    if(!isEmpty(st))
        return st.s[st.top];
    return -1;
}

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}*root=NULL;

void createPre(int pre[],int n)
{
    struct stack st;
    struct node *p,*t;
    int i=0;
    root=(struct node *)malloc(sizeof(struct node));
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;
    while(i<n)
    {
        if(pre[i]<p->data)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=pre[i++];
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            push(&st,p);
            p=t;
        }
        else
        {
            if((pre[i]>p->data && pre[i]<stackTop(st)) || (pre[i]>p->data && pre[i]>0))
            {
                t=(struct node *)malloc(sizeof(struct node));
                t->data=pre[i++];
                t->lchild=t->rchild=NULL;
                p->rchild=t;
                p=t;
            }
            else
            {
                p=pop(&st);
            }
        }
    }
}
void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d->",p->data);
        inorder(p->rchild);
    }
}
int main()
{
    int i,p[8];
    struct stack st;
    create(&st,50);
    printf("enter the elements:\n");
    for(i=0;i<8;i++)
    {
        scanf("%d",&p[i]);
    }

    createPre(p,8);

    inorder(root);

    getch();
}
