#include<stdio.h>
#include<stdlib.h>

void insert(int a[],int n)
{
    int temp,i;
    i=n;
    temp=a[i];
    while(i>1 && temp>a[i/2])
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}

int delet(int a[],int n)
{
    int x,i,temp,val,j;
    val=a[1];
    a[1]=a[n];
    a[n]=val;
    i=1;
    j=2*i;

    while(j<n-1)
    {
        if(a[j+1]>a[j])     //comparing the child node
            j=j+1;
        if(a[i]<a[j])       //replacing with the child nodes
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*i;
        }
        else
            break;
    }
    return val;
}

int createHeap()
{
    int i,n,c;
    int x=1;

    printf("enter the number of elements:\n");
    scanf("%d",&n);
    n+=1;
    int h[n];
    h[0]=0;
    printf("enter the elements\n");
    for(i=1;i<n;i++)
    scanf("%d",&h[i]);

    for(i=2;i<n;i++)
    insert(h,i);

     for(i=1;i<n;i++)
        printf("%d\t",h[i]);

    printf("\n%d deleted \n",delet(h,n-1)); //deletion

    printf("\n%d deleted \n",delet(h,n-2)); //deletion

    printf("new array:\n");
    for(i=1;i<n;i++)
        printf("%d\t",h[i]);
}

int main()
{
    createHeap();

     return 0;
}
