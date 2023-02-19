//
// Created by Joachim Sonigo on 2/17/2023.
//
/*
#include <stdlib.h>
#include <stdio.h>
#define nmax 20

//-----------------------------------------
typedef struct {
    char name [20];
    char surname [20];
    float n1,n2,n3,m;
}student;
//-----------------------------------------
student enter_1_student()
{
    student s ;
    printf("Name: ");
    scanf("%s",&s.name);

    printf("Surname: ");
    scanf("%s",&s.surname);

    do {
        printf("\n1st grade: ");
        scanf("%f",&s.n1);
    }while (s.n1>nmax || s.n1<0);
    do {
        printf("\n2nd grade: ");
        scanf("%f",&s.n2);
    }while (s.n1>nmax || s.n2<0);
    do {
        printf("\n3rd grade: ");
        scanf("%f",&s.n3);
    }while (s.n1>nmax || s.n3<0);

    s.m=(s.n1+s.n2+s.n3)/3;
    return(s);
}

int input_dimension(){
    int n =0;
    do {
        printf("\nHow many students would you like to enter? :");
        scanf("%d",&n);
    } while (n<=0);

    return (n);
}

void enter_n_students(student *s,int n){
    for (int i = 0; i < n; ++i)
        *(s+i) = enter_1_student();
}

void show_1_student(student s){
    printf("\nName: %s\tSurname:%s",s.name,s.surname);
    printf("\nGrades: %.2f\t%.2f\t%.2f",s.n1,s.n2,s.n3);
    printf("\nAverage: %.2f",s.m);
}
void show_n_students(student *s,int n){
    for (int i = 0; i < n; ++i)
        show_1_student(*(s+i));
}



void exo3(){
    int n ; // 0< n < 40
    student *s;
    n=input_dimension(); // 4
    s=(student*) malloc(n*sizeof(student));
    enter_n_students(s,n); // 2
    show_n_students(s,n); // 2
    free(s);
}*/