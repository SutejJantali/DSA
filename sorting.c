//ALL SORT PROGRAMS BY SUTEJ :)


#include<stdlib.h>
#include<stdio.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void ShellSort(int a[],int n)
{
    int gap,i,j,temp;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=a[i];
            j=i-gap;
            while(j>=0 && a[j]>temp)
            {
                a[j+gap]=a[j];
                j=j-gap;
            }
            a[j+gap]=temp;
        }
    }
}

int FindMax(int a[],int n)
{
    int i,max;
    max=-32767;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}

void CountSort(int a[],int n)
{
    int i,j,max,*c;
    max=FindMax(a,n);
    c=(int *)malloc(sizeof(int)*(max+1));

    for(i=0;i<max+1;i++)
        c[i]=0;

    for(i=0;i<n;i++)
    {
        c[a[i]]++;
    }
    i=0;j=0;
    while(j<max+1)
    {
        if(c[j]>0)
        {
            a[i++]=j;
            c[j]--;
        }
        else
            j++;
    }

}

void merge(int a[],int l, int mid,int h)
{
    int i,j,k;
    i=l;
    j=mid+1;
    k=l;
    int b[h+1];

    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    for(;i<=mid;i++)
        b[k++]=a[i];

    for(;j<=h;j++)
        b[k++]=a[j];


    for(i=l;i<=h;i++)
        a[i]=b[i];
}

void IMergeSort(int a[],int n)
{
    int p,i,l,mid,h;

    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<=n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(a,l,mid,h);
        }
    }
    if(p/2<n)
        merge(a,0,p/2-1,n-1);
}

void RMergeSort(int a[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        RMergeSort(a,l,mid);
        RMergeSort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}


int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;
    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);

        if(i<j)
            swap(&a[i],&a[j]);
    }while(i<j);

    swap(&a[l],&a[j]);

    return j;
}

void QuickSort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}

void BubbleSort(int a[],int n)
{
    int i,j,flag,temp;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                flag=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if(flag==0)
            break;
    }
}

void insertionSort(int a[],int n)
{
    int x,i,j;
    for(i=1;i<n;i++)
    {
        j=i-1;
        x=a[i];
        while(j>-1  && a[j]>x)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

void SelectionSort(int a[],int n)
{
    int i,j,k,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(a[j]<a[k])
                k=j;
        }
        temp=a[i];
        a[i]=a[k];
        a[k]=temp;
    }
}

int main()
{
    int n;
    printf("enter the number of elements:\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    //BubbleSort(a,n);
    //insertionSort(a,n);
    //SelectionSort(a,n);
    //QuickSort(a,0,n);
    //IMergeSort(a,n);
    //RMergeSort(a,0,n);
    //CountSort(a,n);

    ShellSort(a,n);

    printf("after sorting:\n");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);

    return 0;
}
