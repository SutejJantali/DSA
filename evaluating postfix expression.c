#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
        printf("stack full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
int pop()
{
    struct node *p;
    int x=-1;
    if(top==NULL)
        printf("stack full\n");
    else
    {
    p=top;
    top=top->next;
    x=p->data;
    free(p);
    }
    return x;
}

void display()
{
    struct node *p;
    p=top;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
int isOperand(char x)
{
    if(x=='+' || x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;

}
int precedence(char x)
{
    if(x=='+'||x=='-')
        return 1;

    if(x=='*'||x=='/')
        return 2;

    return 0;
}
int *IntoPost(int *infix)
{
    int i=0,j=0;
    char *postfix;
    int len=strlen(len);
    postfix=(int *)malloc((len+2)*sizeof(int));

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];

        else
        {
            if(precedence(infix[i])>precedence(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++]=pop();
            }

        }
    }
    while(top!=NULL)
        postfix[j++]=pop();

    postfix[j]='\0';

    return postfix;
}



int eval(char *postfix)
{
    int i=0;
    int x1,x2,r=0;
    for(i=0; postfix[i]!='\0'; i++)
    {
        if(isOperand(postfix[i]))
            push(postfix[i]-'0');
        else
        {
            x2=pop();x1=pop();
            switch(postfix[i])
            {
            case '+':r=x1+x2;break;
            case '-':r=x1-x2;break;
            case '*':r=x1*x2;break;
            case '/':r=x1/x2;break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
  /*  push(' ');
    printf("enter the infix expression:\n");
    char *infix;
    gets(infix);
*/
    char *postfix="23*2-";
    /*printf("enter the postfix:\n");
    gets(postfix);*/
    printf("%d\n",eval(postfix));

    return 0;
}
