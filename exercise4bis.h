//
// Created by Joachim Sonigo on 2/19/2023.
//

#ifndef SESSION3_EXERCISE4BIS_H
#define SESSION3_EXERCISE4BIS_H

#include <stdbool.h>

typedef struct{
    int dd,mm,yy; //birthdate
}date;

typedef struct {
    char name[20], surname[20];
    date ddn;
    float n1, n2, n3, m;
} student;

void line(){
    printf("\n------------------------");
}

int checkdate(int dd,int mm, int yy){
    //check year
    if(yy>=1900 && yy<=9999)
    {
        //check month
        if(mm>=1 && mm<=12)
        {
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){
                printf("Date is valid.\n");
                return 1;}
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)) {
                printf("Date is valid.\n");
                return 1;}
            else if((dd>=1 && dd<=28) && (mm==2)){
                printf("Date is valid.\n");
                return 1;}
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))) {
                printf("Date is valid.\n");
                return 1;
            }
            else
                printf("Day is invalid.\n");
        }
        else
        {
            printf("Month is not valid.\n");
        }
    }
    else
    {
        printf("Year is not valid.\n");
    }
    return 0;
}

void writetocsv(student * s,int N){
    FILE *file;
    file= fopen("C:\\Users\\coolj\\OneDrive\\Documents\\IPSA\\3A-S2\\C++\\Session3\\saveddata.csv","w");
    if(file == NULL){
        printf("\nFile couldn't be opened!");
        return;
    }
    for (int i = 0; i < N; ++i) {
        fprintf(file,"%s,%s,%f,%f,%f,%f,%d,%d,%d\n",(s+i)->name,(s+i)->surname,(s+i)->n1,(s+i)->n2,(s+i)->n3,(s+i)->m,(s+i)->ddn.dd,(s+i)->ddn.mm,(s+i)->ddn.yy);
    }
    printf("\nFile was successfully saved!");
    fclose(file);
}

int countnumbercsv(){
    int n=0;
    FILE *file;
    file= fopen("C:\\Users\\coolj\\OneDrive\\Documents\\IPSA\\3A-S2\\C++\\Session3\\saveddata.csv","r");
    for (char c = getc(file); c != EOF; c = getc(file))
        if (c == '\n') // Increment count if this character is newline
            n=n+1;
    fclose(file);
    printf("\nThis file already has %d students stored inside !",n);
    return n;
}

void showstudentsfromcsv(student * s,int n){
    FILE *file;
    file= fopen("C:\\Users\\coolj\\OneDrive\\Documents\\IPSA\\3A-S2\\C++\\Session3\\saveddata.csv","r");

    /*
    line();
    printf("\nStudents");
    line();
    fprintf(file,"\nFull name : %s %s\nGrades : %f | %f | %f\nAverage : %f\nBirthday : %d/%d/%d");
    line();*/
    fclose(file);
}
#endif //SESSION3_EXERCISE4BIS_H
