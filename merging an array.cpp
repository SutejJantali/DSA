#include<iostream>
using namespace std;
int main()
{
    int i,k,temp,j,m,ele,n;
    cout<<"enter the sizes of array:\n";
    cin>>m>>n;
    k=m+n;
    int a[m],b[n],c[k];
    cout<<"enter the elements:\n";

    for(i=0; i<m; i++)
        cin>>a[i];
    for(j=0; j<n; j++)
        cin>>b[j];
    i=j=k=0;
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
            c[k++]=b[j++];
    }
    for(; i<m; i++) //copying left overs
        c[k++]=a[i];
    for(; j<n; j++)
        c[k++]=b[j];

    for(int x:c)
        cout<<x<<"\t";

    return 0;
}
