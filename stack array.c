#include<stdio.h>
#define size 10
int stack[size],ele,i,top=-1;
void main()
{
    int choice;
    int ch=1;
    while(ch==1)
    {
        printf("enter the choice:\n");
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }

    }
}
int push()
{
    if(top==size-1)
    {
        printf("stack full");
        return;
    }
    printf("enter the element: ");
    scanf("%d",&ele);
    top=top+1;
    stack[top]=ele;
    printf("%d is pushed\n",ele);
}
int pop()
{
    if(top==-1)
        printf("stack is empty\n");
    else
    {
        printf("%d is popped\n",stack[top]);
        top--;
    }
}
int display()
{
    for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);
}
