#include<stdio.h>
#include<stdlib.h>
struct element
{
    int i;
    int j;
    int x;
};
struct sparse
{
    int m;
    int n;
    int num;
    struct element *e;
};
void create(struct sparse *s)
{
    printf("enter the dimensions of the matrix:\n");
    scanf("%d %d",&s->m,&s->n);
    printf("enter the no. of non zero elements\n");
    scanf("%d",&s->num);

    s->e=(struct element*)malloc(s->num*sizeof(struct element));
    printf("enter all the elements\nrow number\t col no\t element\n");

    for(int i=0;i<s->num;i++)
        scanf("%d %d %d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
}
void display(struct sparse s)
{
    int i,j,k=0;
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
            printf("%d ",s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void main()
{
    struct sparse s;
    create(&s);
    display(s);
    return 0;
}
