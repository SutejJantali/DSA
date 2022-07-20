#include<stdio.h>
#include<stdlib.h>
int H(int k,int j)
{
    return ((k%10)+j)%10;
}
int main()
{
    int *HashTable;
    HashTable=(int *)malloc(10*sizeof(int));
    int i,n,key,hashvalue;
    int j;
    for(i=0;i<n;i++)
        HashTable[i]=-1;

    printf("number of keys: ");
    scanf("%d",&n);

    int *keytable;
    keytable=(int *)malloc(n*sizeof(int));
    printf("enter all the keys:\n");
    for(i=0;i<n;i++)
        scanf("%d",&keytable[i]);

    for(i=0;i<n;i++)
    {
        j=0;
        key=keytable[i];
        while(j<=9 && HashTable[H(key,j)]!=-1)
            j++;
        if(HashTable[H(key,j)]==-1)
           HashTable[H(key,j)]=key;


    }
    printf("hash table:\n");
    for(i=0;i<=n;i++)
    {
         if(HashTable[i]==-1)
            continue;
        printf("hashtable[index=%d]->%d\n",i,HashTable[i]);

   }
    return 0;
}
