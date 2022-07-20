#include<iostream>
using namespace std;
int main()
{
    int i,temp,j,n;
    cout<<"enter the size of array:\n";
    cin>>n;
    int a[n];
    cout<<"enter the elements:\n";

    for(i=0; i<n; i++)
        cin>>a[i];
    temp=a[0];
    cout<<"rotation:\n";

    for(i=0; i<n-1; i++)
        a[i]=a[i+1];
    a[n-1]=temp;

    for(i=0; i<n; i++)
        cout<<a[i]<<"\t";
    cout<<"left shift:\n";

    for(i=0; i<n-1; i++)
        a[i]=a[i+1];
    a[n-1]=0;

    for(i=0; i<n; i++)
        cout<<a[i]<<"\t";
    return 0;
}
