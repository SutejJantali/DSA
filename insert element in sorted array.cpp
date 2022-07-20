#include<iostream>
using namespace std;
int main()
{
    int i,temp,j,ele,n;
    cout<<"enter the size of array:\n";
    cin>>n;
    int a[n];
    cout<<"enter the elements:\n";

    for(i=0; i<n; i++)
        cin>>a[i];
    cout<<"array after sorting is:\n";
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0; i<n; i++)
        cout<<a[i]<<"\t";
    cout<<"\n enter the insertion element:\n";
    cin>>ele;
    i=n-1;
    while(a[i]>ele)
    {
        a[i+1]=a[i];
        i--;
    }
    n++;
    a[i+1]=ele;
    for(i=0; i<n; i++)
        cout<<a[i]<<"\n";
    return 0;
}
