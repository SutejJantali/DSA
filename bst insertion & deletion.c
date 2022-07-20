#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;
void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d\n",p->data);
        inorder(p->rchild);
    }
}
struct node *Rinsert(struct node *p,int key)
{
    struct node *t=NULL;
    if(p==NULL)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=key;
        t->lchild=t->rchild=NULL;

        return t;

    }
    if(key<p->data)
        p->lchild=Rinsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=Rinsert(p->rchild,key);

    return p;

}
int height(struct node *p)
{
    int x,y;
    if(p==NULL)return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}
struct node *inpre(struct node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;

    return p;
}
struct node *insucc(struct node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;

    return p;
}
/*int insert(int key)
{
    struct node *t=root,*r=NULL,*p;
    if(root==NULL)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return ;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
        {
            t=t->lchild;
        }
        else if(key>t->data)
            t=t->rchild;
        else
            return;
    }
    p=(struct node *)malloc(sizeof(struct node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)
        r->lchild=p;
        else
            r->rchild=p;
}*/


struct node *delet(struct node *p,int key)
{
    struct node *q;
    if(p==NULL)
        return NULL;
    if(p->data ==key)
    {
        if(p->lchild==NULL && p->rchild==NULL)
        {
            if(p==root)
                root=NULL;
            free(p);
            p=NULL;
            return NULL;
        }
        if(p->lchild==NULL && p->rchild!=NULL)
        {
            q=p->rchild;
            free(p);
            return q;
        }
        if(p->lchild!=NULL && p->rchild==NULL)
        {
            q=p->lchild;
            free(p);
            return q;
        }
        if(p->lchild!=NULL && p->rchild!=NULL)
        {
            if(height(p->lchild)>height(p->rchild))
            {
                q=inpre(p->lchild);
                p->data=q->data;
                p->lchild=delet(p->lchild,q->data);

            }
            else
            {
                q=insucc(p->rchild);
                p->data=q->data;
                p->rchild=delet(p->rchild,q->data);

            }
        }
    }
        if(key<p->data)
            p->lchild=delet(p->lchild,key);

        else if(key>p->data)
            p->rchild=delet(p->rchild,key);

        return p;

    }



int main()
{
    root=Rinsert(root,10);
    Rinsert(root,20);
    Rinsert(root,40);
    Rinsert(root,30);
    Rinsert(root,50);
    inorder(root);
    printf("\n");
    delet(root,20);
    inorder(root);

    return 0;
}
