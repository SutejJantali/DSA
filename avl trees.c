#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
    int height;
}*root=NULL;

int NodeHeight(struct node *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(struct node *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl-hr;
}

struct node *LLRotation(struct node *p)
{
    struct node *pl=p->lchild;
    struct node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root==p)
        root=pl;


    return pl;

}

struct node *RRRotation(struct node *p)
{
    struct node *pr=p->rchild;
    struct node *prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    if(root=p)
        root=pr;

    return pr;
}

struct node *LRRotation(struct node *p)
{
    struct node *pl=p->lchild;
    struct node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);

    if(root==p)
        root=plr;

    return plr;
}

struct node *RLRotation(struct node *p)
{
    struct node *pr=p->rchild;
    struct node *prl=pr->lchild;

    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;

    prl->lchild=p;
    prl->rchild=pr;

    pr->height=NodeHeight(pr);
    p->height=NodeHeight(p);
    prl->height=NodeHeight(prl);

    if(root==p)
        root=prl;

    return prl;
}

struct node *RInsert(struct node *p,int key)
{
    struct node *t=NULL;
    if(p==NULL)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        t->height=1;
        return t;
    }
    if(key<p->data)
        p->lchild=RInsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=RInsert(p->rchild,key);

    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);

    return p;
}

void preorder(struct node *p)
{
    if(p)
    {
        printf("%d=>",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    root=RInsert(root,10);
    RInsert(root,20);
    RInsert(root,30);
    RInsert(root,25);
    RInsert(root,28);
    RInsert(root,27);
    RInsert(root,5);


    preorder(root);

    return 0;
}
