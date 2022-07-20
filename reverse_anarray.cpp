/*#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cout<<"enter the size of array:\n";
    cin>>n;
    int a[n],b[n];
    cout<<"enter the elements\n:";
    for(i=0; i<n; i++)
        cin>>a[i];
    cout<<"reversed array is:\n";
        for(i=n-1,j=0; i>=0; i--,j++)
    {
        b[j]=a[i];
    }
    for(int x:b)
        cout<<x<<"\t";

    return 0;
}
*/
#include<iostream>
using namespace std;
int main()
{
 int i,j,temp,n;
    cout<<"enter the size of array:\n";
    cin>>n;
    int a[n],b[n];
    cout<<"enter the elements\n:";
    for(i=0; i<n; i++)
        cin>>a[i];
    cout<<"reversed array is:\n";
       for(i=n-1,j=0; j<i; i--,j++)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
      for(int x:a)
        cout<<x<<"\t";

    return 0;
}

