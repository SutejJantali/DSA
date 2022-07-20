#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int front;
    int size;
    int rear;
    struct node **Q;
};
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct node **)malloc(q->size*sizeof(struct node *));
}
void enqueue(struct Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
        printf("queue is full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct node *dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
        printf("queue is empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}

struct node *root=NULL;

void treecreate()
{
    struct node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("enter the root value:\t");
    scanf("%d",&x);
    root=(struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("enter left child of %d\t",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("enter right child of %d\t",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
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
void postorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        inorder(p->rchild);
        printf("%d->",p->data);

    }
}
void preorder(struct node *p)
{
    if(p)
    {
        printf("%d->",p->data);
        inorder(p->lchild);
        inorder(p->rchild);
    }
}

int main()
{
    treecreate();
    printf("inorder:\n");
    inorder(root);
    printf("\npreorder:\n");
    preorder(root);
    printf("\npostorder:\n");
    postorder(root);
    return 0;
}
