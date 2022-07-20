#include<iostream>
using namespace std;
int main()
{
    int n,maxi,mini,counting;
    cout<<"enter the size of array:"<<endl;
    cin>>n;
    cout<<"enter the array:"<<endl;
    int i,j,k,a[n];
    for(i=0; i<n; i++)
        cin>>a[i];
    mini=a[0];
    maxi=a[0];
    for(i=1; i<n; i++)
    {
        if(a[i]<mini)
            mini=a[i];
        if(a[i]>maxi)
            maxi=a[i];
    }
    cout<<"maximum is: "<<maxi<<endl<<"minimum is: "<<mini<<endl;
    return 0;
}
