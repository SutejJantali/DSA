#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root=NULL;

struct node *createtree(char postfix[])
{
    struct node *temp,*stack[20];
    int i=0,j=0;
    char symbol;
    for(i=0;(symbol=postfix[i])!=0;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->left=temp->right=0;
        temp->data=symbol;
        if(isalnum(symbol))
            stack[j++]=temp;
        else
        {
            temp->left=stack[--j];
            temp->right=stack[--j];
            stack[j++]=temp;
        }
    }
    return (stack[--j]);
}
float eval(struct node *root)
{
    float num;
    switch(root->data)
    {
        case '+':return eval(root->left)+eval(root->right);
        case '-':return eval(root->left)-eval(root->right);
        case '*':return eval(root->left)*eval(root->right);
        case '/': return eval(root->left)/eval(root->right);
        case '^':return pow(eval(root->left),eval(root->right));

        default:if(isalpha(root->data))
                {
                    printf("enter the value of %c\n",root->data);
                    scanf("%f",&num);
                    return (num);
                }
                else
                return (root->data-'0');
    }
}
void main()
{
    char postfix[20];
    float result;
    printf("enter the postfix expression\n");
    scanf("%s",postfix);
    root=createtree(postfix);
    result=eval(root);
    printf("%f",result);
    //getch();
}
