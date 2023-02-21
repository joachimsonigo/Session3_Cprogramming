#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercise4bis.h"
//-----------------------------------
// struct
//-----------------------------------

//-----------------------------------
// func
//-----------------------------------

date enterdate() {
    date result;
    int boolcheck =0;
    do {
        printf("\nBirthdate : \n(DD/MM/YYYY format)\n");
        scanf("%d/%d/%d",&result.dd,&result.mm,&result.yy);
        boolcheck = checkdate(result.dd,result.mm,result.yy);
    }while(boolcheck!=1);
    return result;
}

student Enter_1_Student(int n) {
    student s;
    printf("\n------------------------");
    printf("\nStudent # %d:", n);
    printf("\n------------------------");
    printf("\nName : ");
    scanf("%s", &s.name);
    printf("Surname : ");
    scanf("%s", &s.surname);
    do {
        printf("1st grade:", s.n1);
        scanf("%f", &s.n1);
    } while (0 > s.n1 || s.n1 > 20);
    do {
        printf("2nd grade :", s.n2);
        scanf("%f", &s.n2);
    } while (0 > s.n2 || s.n2 > 20);
    do {
        printf("3rd grade :", s.n3);
        scanf("%f", &s.n3);
    } while (0 > s.n3 || s.n3 > 20);

    s.m = (s.n1 + s.n2 + s.n3) / 3;

    s.ddn = enterdate();
    return (s);
}

//-----------------------------------

void show_1_student(student s, int n) {
    printf("\n--------------\nStudent %d\n--------------", n);
    printf("\nName: %s", s.name);
    printf("\nSurname: %s", s.surname);
    printf("\nGrade 1: %.2f", s.n1);
    printf("\nGrade 2: %.2f", s.n2);
    printf("\nGrade 3: %.2f", s.n3);
    printf("\nAverage: %.2f", s.m);
    printf("\nBirthdate : %d/%d/%d",s.ddn.dd,s.ddn.mm,s.ddn.yy);
}
//-----------------------------------
// n student
//-----------------------------------
int numberstudent() {
    int n;
    do {
        printf("\nEnter the number of student:  ");
        scanf("%d", &n);
    } while (n < 0);
}

//-----------------------------------

student Enter_n_student(student *s, int d, int f) {
    int i;
    for (i = d; i < f; i++) {
        *(s + i) = Enter_1_Student(i + 1);
        system("pause");
    }
}

//-----------------------------------

void show_n_student(student *s, int n) {
    int i;
    printf("\n------------------------");
    printf("\n   Results : %d students  ", n);
    printf("\n------------------------");
    for (i = 0; i < n; i++)
        show_1_student(*(s + i), i + 1);
}

void comparename(student *s,char *n,int N){
    int result =1;
    for (int i = 0; i < N; ++i) {
        result = strcmp((s + i)->name, n);
        if(result ==0){
            show_1_student(*(s+i),N);
            break;
        }
    }
}

void comparelastname(student *s,char *n,int N){
    int result =1;
    for (int i = 0; i < N; ++i) {
        result = strcmp((s + i)->surname, n);
        if(result ==0){
            show_1_student(*(s+i),N);
            break;
        }
    }
}

void comparebirth(student *s,int dd,int mm,int yy,int N){
    int result =1;
    int n[3]={dd,mm,yy};
    for (int i = 0; i < N; ++i) {
        if((s + i)->ddn.yy == n[2]){
            if((s+i)->ddn.mm == n[1]) {
                if ((s + i)->ddn.dd == n[0]) {
                    show_1_student(*(s + i), (i+1));
                    break;
                }
                else
                    printf("\nno students have this date of birth in the system");
            }
            else
                printf("\nno students have this date of birth in the system");
        }
        else
            printf("\nno students have this date of birth in the system");
    }
}
void modify(student *s, int n) {
    char name[20], surname[20];
    int i, N = 0;
    printf("\nPlease enter the name and surname of the student you want to modify: ");
    printf("\nName: ");
    scanf("%s", name);
    printf("\nSurname: ");
    scanf("%s", surname);

    for (i = 0; i < n; i++) {
        if (strcmp((s+i)->name, name) == 0 && strcmp((s+i)->surname, surname) == 0) {
            N = 1;
            break;
        }
    }
    if (N == 1) {
        printf("\nStudent record for %s %s found.\n", name, surname);
        printf("\nEnter the new data for the student:\n");
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Surname: ");
        scanf("%s", s[i].surname);
        printf("Grade 1: ");
        scanf("%f", &(s+i)->n1);
        printf("Grade 2: ");
        scanf("%f", &(s+i)->n2);
        printf("Grade 3: ");
        scanf("%f", &(s+i)->n3);
        (s+i)->ddn = enterdate();
        printf("New data for %s %s updated.\n", (s+i)->name, (s+i)->surname);
        writetocsv(s,n);
    } else {
        printf("\nStudent record for %s %s not found.\n", name, surname);
    }
}

void erase(student *s, int n) {
    char name[20], surname[20];
    int i, j, N = 0;
    printf("\nPlease enter the name and surname of the student : ");
    printf("\nName : ");
    scanf("%s", name);
    printf("\nSurname : ");
    scanf("%s", surname);

    for (i = 0; i < n; i++) {
        if (strcmp((s+i)->name, name) == 0 && strcmp((s+i)->surname, surname) == 0) {
            N = 1;
            break;
        }
    }
    if (N==1) {
        for (j = i; j < n - 1; j++)
            *(s+j) = *(s + j + 1);
        printf("Student record for %s %s erased.\n", name, surname);
    } else {
        printf("Student record for %s %s not found.\n", name, surname);
    }
}
void search(student *s,int N){
    char sn,sl=0;
    int dd,mm,yy=0;
    line();
    printf("\nSearch Menu");
    line();
    printf("\nHow would you like to look up the student?");
    line();
    int choiceSearch=0;
    do {
        printf("\n1. By name\n2. By last name\n3. By date of birth\n4. Exit");
        line();
        scanf("%d",&choiceSearch);
    } while (choiceSearch<0 || choiceSearch>4);
    switch (choiceSearch) {
        case 1:{
            printf("\nPlease enter the student's name");
            scanf("%s",&sn);
            comparename(s,&sn,N);
            break;
        }
        case 2:{
            printf("\nPlease enter the student's last name");
            scanf("%s",&sl);
            comparelastname(s,&sl,N);
            break;
        }
        case 3:{
            int booldate=0;
            do {
                printf("\nPlease enter the student's date of birth ");
                printf("\nEnter date (DD/MM/YYYY format): ");
                scanf("%d/%d/%d",&dd,&mm,&yy);
                booldate = checkdate(dd,mm,yy);
            }while(booldate != 1);
            comparebirth(s,dd,mm,yy,N);
            break;
        }
        case 4:
            break;
    }
}
//-----------------------------
//--------MAIN PROGRAM---------
//-----------------------------
void exo4() {
    student *s;
    int n, g, N = 0;
    char sn,sl,sd;
    N = countnumbercsv();
    do {
        do {
            printf("\n------------------------");
            printf("\n         Menu ");
            printf("\n------------------------");
            printf("\n 1- Enter_Student");
            printf("\n 2- Show_Student");
            printf("\n 3- Search Student");
            printf("\n 4- Modify Student");
            printf("\n 5- Erase Student");
            printf("\n 6- END ");
            printf("\n------------------------");
            printf("\n What is your choice ? : ");
            printf("\n------------------------\n");
            scanf("%d", &g);
        } while (g <= 0 || g > 6);

        if (g == 1) {
            if (N == 0) {
                n = numberstudent();
                s = (student *)malloc(n * sizeof(student));
                Enter_n_student(s, 0, n);
                N = N + n;
            } else {
                n = numberstudent();
                s = (student *)realloc(s, (N + n) * sizeof(student));
                Enter_n_student(s, N, N + n);
                N = N + n;
                // printf(" en travail ") ;
            }
            int choicew=0;
            do {
                printf("\nWould you like to write to file?\n(1 for yes and 0 for no)");
                scanf("%d",&choicew);
            }while(choicew<0 || choicew>1);
            if(choicew==1)
                writetocsv(s,N);
        }

        if (g == 2) {
            int choicep=0;
            if(countnumbercsv()==0){
                show_n_student(s, N);
                printf("\n");
                system("pause");
            }
            else{
                do {
                    printf("\nWould you like to print out the csv file or the current student array?\n1. Student array\n2. CSV file\n");
                    scanf("%d",&choicep);
                }while(choicep <1 || choicep>2);
                switch (choicep) {
                    case 1:{
                        show_n_student(s, N);
                        printf("\n");
                        system("pause");
                    }
                    case 2:{
                        showstudentsfromcsv(s,N);
                        system("pause");
                    }
                }
            }
        }
        if (g == 3){
            search(s,N);
        }
        if(g == 4){
            modify(s,N);
        }
        if(g == 5){
            erase(s,N);
            N--;
            s = (student *)realloc(s,(N) * sizeof(student));
            writetocsv(s,N);
            system("pause");
        }
    } while (g != 6);
    free(s);
}

