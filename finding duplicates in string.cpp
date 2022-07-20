#include<stdio.h>
#include<conio.h>
void swa();
void permutations();
int main()
{
    int j,i,n;
    printf("enter the size of array:\n");
    scanf("%d",&n);
    char a[n];
    for(i=0; i<n; i++)
        scanf("%c",a[i]);
    permutations(a,0,n-1);
    return 0;
}
void permutations(char s[],int l,int h)
{
    int i;
    if(l==h)
    {
        printf("%s",s);
    }
    else
    {
        for(i=0; i<=h; i++)
        {
            swa(&s[l],&s[h]);
            permutations(s,l+1,h);
            swa(&s[l],&s[i]);
        }
    }
}
void swa(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
