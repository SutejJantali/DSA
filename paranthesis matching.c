#include<stdio.h>
struct node
{
    char data;
    struct node *next;
}*top=NULL;

char push(char x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
        printf("stack overflow\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
void pop()
{
    struct node *p;
    char x=-1;
    if(top==NULL)
        printf("stack is empty\n");

    else
    {
        p=top;
        top=top->next;
        x=p->data;
        free(p);
    }
    return x;
}

int peek(int pos)
{
    int x=-1,i;
    struct node *p=top;
    for(i=0;p!=NULL && i<pos-1;i++)
        p=p->next;

    if(p!=NULL)
        return p->data;
    else
            return -1;
}
int stacktop()
{
    if(top)
        return top->data;
    return -1;
}

int isEmpty()
{
    return top?0:1;
}

int isFull()
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    int r=t?1:0;

    free(t);
    return r;

}
int isbalanced(char *exp)
{
    int i;

    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp);
        else if(exp[i]==')')
        {
            if(top==NULL)
                return 0;
            pop();
        }
    }
    if(top==NULL)
        return 1;
        else
        return 0;
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

int main()
{
        char *exp="((a+b)*(c-d))";
        /*push(10);
        push(20);
        push(30);
        display();
        pop();*/
       printf("%d",isbalanced(exp));
        //display();
        return 0;
}
