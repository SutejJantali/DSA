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
    i=0;
    j=n-1;
    while(i<j)
    {
        while(a[i]<0)
        {
            i++;
        }
        while(a[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
           int temp;
           temp=a[i];
           a[i]=a[j];
           a[j]=temp;
        }
    }
    for(int x:a)
        cout<<x<<"\t";

    return 0;
}
