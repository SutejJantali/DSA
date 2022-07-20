#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(char x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
        printf("size full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop()
{
    struct node *t;
    char x=-1;
    if(top==NULL)
        printf("stack empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
        return x;
    }
}
void display()
{
    struct node *p;
    p=top;

    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int precedence(char x)
{
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;

    return 0;
}
int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;
}
char *InToPost(char *infix)
{
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(precedence(infix[i])>precedence(top->data))
                push(infix[i++]);
            else
                postfix[j++]=pop();
        }
    }
    while(top!=NULL)
        postfix[j++]=pop();

    postfix[j]='\0';

    return postfix;
}
int main()
{
    char str[20];
    char *infix;
    push(' ');
    printf("enter the expression:\t");
    gets(str);
    infix=str;
    char *postfix=InToPost(infix);

    printf("%s\n",postfix);
    return 0;
}
