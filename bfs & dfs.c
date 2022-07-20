#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));

    if(t==NULL)
        printf("queue full\n");

    else
    {
        t->data=x;
        t->next=NULL;

        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue()
{
    struct node *p;
    int x=-1;
    if(front==NULL)
        printf("queue empty\n");
    else
    {
        x=front->data;
        p=front;
        front=front->next;
        free(p);
    }
    return x;
}

int isEmpty()
{
    return front==NULL;
}

void bfs(int g[][7],int start,int n)
{
    int i=start,j;
    int visited[7]={0};
    printf("%d\t",i);
    visited[i]=1;

    enqueue(i);
    while(!isEmpty())
    {
        i=dequeue();
        for(j=1;j<n;j++)
        {
            if(g[i][j]==1 && visited[j]==0)
            {
                printf("%d\t",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }

}

void dfs(int g[][7],int start,int n)
{
    static int visited[7]={0};
    int j;

    if(visited[start]==0)
    {
        printf("%d\t",start);
        visited[start]=1;
        for(j=1;j<n;j++)
        {
            if(g[start][j]==1 && visited[j]==0)
                dfs(g,j,n);
        }

    }

}

int main()
{                                               //TREE
    int  g[][7]={{0,0,0,0,0,0,0},     //               (1)
                 {0,0,1,1,0,0,0},       //            /   /
                 {0,1,0,0,1,0,0},       //           (2)  (3)
                 {0,1,0,0,1,0,0},       //             \ /
                 {0,0,1,1,0,1,1},        //            (4)
                 {0,0,0,0,1,0,0},          //          / /
                 {0,0,0,0,1,0,0}, };    //          (5)  (6)

    printf("breadth first search:\n");
    bfs(g,4,7);
    printf("\n");
    printf("depth first search:\n");
    dfs(g,4,7);
    return 0;
}
