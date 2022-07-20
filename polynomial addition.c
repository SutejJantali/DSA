#include<stdio.h>
#include<conio.h>
struct term
{
    int coeff;
    int exp;
};
struct poly
{
    int n;
    struct term *t;
};
void create(struct poly *p)
{
    int i;
    printf("enter the number of terms:\n");
    scanf("%d",&p->n);

    p->t=(struct term *)malloc(p->n*sizeof(struct term));
    printf("enter the terms:\n coefficient\t exp\n");
    for(i=0; i<p->n; i++)
        scanf("%d %d",&p->t[i].coeff,&p->t[i].exp);
}
void display(struct poly p)
{
    int i;
    for(i=0; i<p.n; i++)
    {
        if(p.t[i].exp==0)
            {
                printf("%d",p.t[i].coeff);
                return 0;
            }
        printf("%dx^%d + ",p.t[i].coeff,p.t[i].exp);
    }
    printf("\n");
}

int main()
{
    struct poly p1;
    create(&p1);
    display(p1);
    return 0;
}
