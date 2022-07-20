#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define max 100
char st[max], infix[100], postfix[100], temp[100];
int top=-1;
void push(char st[], char);
char pop(char st[]);
void reverse(char str[]);
void InfixToPostfix(char source[], char target[]);
int getPriority(char);
int main()
{
    printf("\nEnter any infix expression: ");
    gets(infix);
    reverse(infix);
    strcpy(postfix, "");
    InfixToPostfix(temp, postfix);
    printf("\nThe corresponding postfix expression is: ");
    puts(postfix);
    strcpy(temp, "");
    reverse(postfix);
    printf("\nThe prefix expression is: \n");
    puts(temp);
    getch();
    return 0;
}

void reverse(char str[])
{
    int len, i=0, j=0;
    len=strlen(str);
    j=len-1;
    while(j>=0)
    {
        if(str[j]=='(')
            temp[i]=')';
        else if(str[j]==')')
            temp[i]='(';
        else
            temp[i]=str[j];
        i++, j--;
    }
    temp[i]='\0';
}

void InfixToPostfix(char source[], char target[])
{
    int i=0, j=0;
    char temp;
    strcpy(target, "");
    while(source[i]!='\0')
    {
        if(source[i]=='(')
        {
            push(st, source[i]);
            i++;
        }
        else if(source[i]==')')
        {
            while((top!=-1)&& (st[top]!='('))
            {
                target[j]=pop(st);
                j++;
            }
            if(top==-1)
            {
                printf("\nIncorrect expression");
                exit(1);
            }
            temp=pop(st);//remove left parenthesis
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i]))
        {
            target[j]=source[i];
            j++; i++;
        }
        else if(source[i]=='+' || source[i]=='-' ||source[i]=='*' ||source[i]=='/' ||source[i]=='%')
        {
            while((top!=-1) && (st[top]!='(') && (getPriority(st[top]) > getPriority(source[i])))
            {
                target[j]=pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        }
        else
        {
            printf("\nIncorrect Element in expression");
            exit(1);
        }
    }
    while((top!=-1) && (st[top]!='('))
    {
        target[j]=pop(st);
        j++;
    }
    target[j]='\0';
}

int getPriority(char op)
{
    if(op=='/' || op=='*'|| op=='%')
        return 1;
    else if(op=='+' || op=='-')
        return 0;
}

void push(char st[], char val)
{
    if(top==max-1)
        printf("\nStack overflow");
    else
    {
        top++;
        st[top]=val;
    }
}

char pop(char st[])
{
    char val=' ';
    if(top==-1)
        printf("\nStack Underflow");
    else
    {
        val=st[top];
        top--;
    }
    return val;
}
