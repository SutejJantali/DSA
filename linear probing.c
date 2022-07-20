#include<stdio.h>
#define size 10

int hash(int key)
{
    return key%size;
}
int probe(int h[],int key)
{
    int index,i=0;
    index=hash(key);

    while(h[(index+i)%size]!=0)
        i++;

    return (index+i)%size;
}

void insert(int h[],int key)
{
    int index;
    index=hash(key);

    if(h[index]!=0)
        index=probe(h,key);

    h[index]=key;
}

int search(int h[],int key)
{
    int index,i=0;
    index=hash(key);

    while(h[(index+i)%size]!=key && h[(index+i)%size]!= NULL)
          i++;

    if(h[(index+i)%size]==NULL)
        return NULL;

    return (index+i)%size;
}


int main()
{
    int ht[10]={0};

    insert(ht,12);
    insert(ht,25);
    insert(ht,35);
    insert(ht,26);

    if(search(ht,12))
    printf("\n key found at location %d\n",search(ht,12));

    else
        printf("not found\n");

    return 0;
}
