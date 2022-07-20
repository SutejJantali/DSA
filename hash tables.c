#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[100],a1[100],a2[100],i,result,n;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        result=a[i]%10;
        a1[result]=a2[i]=a[i];
        printf("location:a1[%d],value:%d\n",result,a1[result]);
    }
    printf("hash table is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a2[i]);
    return 0;
}
