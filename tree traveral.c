#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d=>",root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d=>",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d=>",root->data);
}
struct node* createnode(int value)
{
    struct node* newnode=malloc(sizeof(struct node));
    newnode->right=newnode->left=NULL;
    newnode->data=value;
    return newnode;
}
struct node* insertleft(struct node *root,int value)
{
 root->left=createnode(value);
 return root->left;
}
struct node* insertright(struct node* root,int value)
{
    root->right=createnode(value);
    return root->right;
}
int main()
{
    int r,f=1,choice,val;
    struct node* root;
    printf("enter the value of root node: ");
    scanf("%d",&r);
    root=createnode(r);
    while(f==1)
    {
       int  e=1,c=1,x;
    printf("enter 1 for a left node and 2 for a right node\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
                while(c==1)
                {
                printf("enter value: ");
                scanf("%d",&val);
                printf("root or roots left? 1 or 2");
                scanf("%d",&x);
                if(x==1)
                insertleft(root,val);
                else
                insertleft(root->left,val);
                printf("continue again? 1 for yes\n");
                scanf("%d",&c);
                }
                break;
    case 2:     while(e==1)
                {
                printf("enter value: ");
                scanf("%d",&val);
                printf("root or roots right? 1 or 2");
                scanf("%d",&x);
                if(x==1)
                insertright(root,val);
                else
                insertright(root->left,val);
                printf("continue again? 1 for yes\n");
                scanf("%d",&e);
                }
                break;
    default: printf("wrong choice :(\n");

    }
    printf("want to continue? 1-y 0-n");
    scanf("%d",&f);
    }

    printf("inorder:\n");
    inorder(root);

    printf("\npreorder\n");
    preorder(root);

    printf("\npostorder\n");
    postorder(root);

}
