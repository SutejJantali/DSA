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
    for(i=0;i<m;)
    {
        if(a[i]!=b[j])
        {
            c[k++]=a[i++];
            j++;
        }
        else
        {
            i++,j++;
        }
    }
    for(k=0;c[k]!=0;k++)
        cout<<c[k]<<"\t";

    return 0;
}
