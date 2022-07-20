#include<iostream>
using namespace std;
/*int main()
{
    int i,j,a[3][4];
    cout<<"enter the elements of array:"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
            cin>>a[i][j];
    }
    cout<<"array elements are:"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
                cout<<a[i][j];
                cout<<endl;
        }
    }

}*/
/*int main()
{
    int i,j,*a[3];
    a[0]=new int[4];
    a[1]=new int[4];
    a[2]=new int[4];
    cout<<"enter the elements of array:"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"array elements are:"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            cout<<a[i][j];
            cout<<endl;
        }
    }
    return 0;
}*/
int main()
{
    int **a,i,j;
    a=new int*[3];
      a[0]=new int[4];
    a[1]=new int[4];
    a[2]=new int[4];
     cout<<"enter the elements of array:"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"array elements are:"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            cout<<a[i][j];
            cout<<endl;
        }
    }
    return 0;

}
