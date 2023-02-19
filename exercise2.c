//
// Created by Joachim Sonigo on 2/17/2023.
//
#include<stdio.h>
#include<stdlib.h>
#define nmax 20


int enter_n()
{   int n ;
    do{
        printf(" n : ( 0<n<%d) :",nmax);
        scanf("%d",&n);
    }while (0>=n|| n>=nmax);
    return(n);
}
//-----------------------------------------
void enter_tableau(int *t,int n)
{ int i ;
    for(i=0;i<n;i++)
    {
        printf("\n Give me t[%d]: ", i);
        scanf("%d",(t+i));
    }
}
void show_tableau(int t[nmax],int n)
{  int i ;
    printf("\n t : ");
    for(i=0;i<n;i++)

        printf("\t %d ", *(t+i));
}
//-----------------------------------------
void sum_tableau(int * t, int n, int * s){
    *s=0;
    for(int i=0;i<n;i++)
        *s+=*(t+i);
}
//-----------------------------------------
void product_tableau(int * t,int n, int * p)
{
    *p = 1;
    for(int i=0;i<n;i++)
        *p= *p* *(t+i);
}
//-----------------------------------------
void average_tableau(int *t,int n,float *m)
{   int s;
    sum_tableau(t,n,&s);
    *m=(float)s/(float)n;
}
//-----------------------------------------
void maximum_tableau(int * t,int n,int * maxi,int * posmaxi)
{ int i;
    *maxi = *t;
    *posmaxi=0;

    for (i=0;i<n;i++)
    {


        if(*maxi < *(t+i))
        {
            *maxi = *(t+i);
            *posmaxi=i;

        }
    }
}
//-----------------------------------------
void minimum_tableau(int * t,int n,int * mini,int * posmini)
{   *mini= *t;
    *posmini = 0;

    for (int i=1;i<n;i++)
    {
        if(*mini>*(t+i))
        {
            *mini= *(t+i);
            *posmini=i;
        }
    }
}

//-----------------------------------------
void exo2(){

    int n,z,i,r,s,p,posmaxi, mini, posmini;
    int *maxi;
    int *t;
    float m;
    n = enter_n();
    t = (int*) malloc(n*sizeof(int));
//-----------------------------------------
    enter_tableau(t,n);
    show_tableau(t,n);
    sum_tableau(t,n,&s);
    printf("\nThe sum is : %d " , s);
    product_tableau(t,n,&p);
    printf("\nThe product is: %d",p);
    average_tableau(t,n,&m);
    printf("\nThe average value is : %.2f",m);
    maximum_tableau(t,n,&maxi,&posmaxi);
    printf("\nThe maximum value is %d and is reached in %d",maxi,posmaxi);
    minimum_tableau(t,n,&mini,&posmini);
    printf("\nThe minimum value is %d and is reached in %d",mini,posmini);
    /*
//-----------------------------------------
    s= sum_tableau(t,n);
//-----------------------------------------
    z= product_tableau(t,n);
//-----------------------------------------
    m=average_tableau(t,n);
//-----------------------------------------
    posmaxi =  maximum_tableau(t,n);
//-----------------------------------------
    posmini =  minimum_tableau(t,n);
//-----------------------------------------
    maxi = (t+posmaxi);
//-----------------------------------------
    mini = (t+posmini);
//-----------------------------------------






    printf("\n-----------------------------------");
    printf("\n              Results");
    printf("\n-----------------------------------");
    show_tableau(t,n);
    printf("\n-----------------------------------");
    printf("\n Sum     : %d", s );
    printf("\n Product : %d", z);
    printf("\n Average : %d", m);
    printf("\n Maximum : %d at the position : %d",maxi,posmaxi);
    printf("\n Minimum : %d at the position : %d",mini,posmini);
    printf("\n-----------------------------------");
     */
free(t);
}