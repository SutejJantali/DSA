#include<iostream>
using namespace std;
int main()
{
    int n,counting;
    cout<<"enter the size of array:"<<endl;
    cin>>n;
    cout<<"enter the array:"<<endl;
    int i,j,k,a[n];
    for(i=0; i<n; i++)
        cin>>a[i];
    cout<<"sum of pairs for k is:"<<endl;
    cin>>k;
    for(i=0; i<n; i++)
    {
        counting=1;
        if(a[i]!=-1)
        {
            for(j=i+1; j<n; j++)
            {
                if(a[i]+a[j]==k)
                {
                    cout<<a[i]<<"+"<<a[j]<<"="<<k<<endl;
                    cout<<"pairs are:("<<a[i]<<","<<a[j]<<")"<<endl;
                }
            }
        }

    }
    return 0;
}

