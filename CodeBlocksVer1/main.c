#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------------------------------
// struct
//-----------------------------------

typedef struct {
  char name[20], surname[20];
  float n1, n2, n3, m;
} student;

//-----------------------------------
// func
//-----------------------------------

student Enter_1_Student(int n) {
  student s;
  printf("\n------------------------");
  printf("\nStudent n°%d:", n);
  printf("\n------------------------");
  printf("\nName : ");
  scanf("%s", &s.name);
  printf("Surname : ");
  scanf("%s", &s.surname);
  do {
    printf("Note 1 :", s.n1);
    scanf("%f", &s.n1);
  } while (0 > s.n1 || s.n1 > 20);
  do {
    printf("Note 2 :", s.n2);
    scanf("%f", &s.n2);
  } while (0 > s.n2 || s.n2 > 20);
  do {
    printf("Note 3 :", s.n3);
    scanf("%f", &s.n3);
  } while (0 > s.n3 || s.n3 > 20);
  s.m = (s.n1 + s.n2 + s.n3) / 3;
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
    system("cls");
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

//-----------------------------
//--------MAIN PROGRAMM--------
//-----------------------------
main() {
  student *s;
  int n, g, N = 0;
  do {
    do {
      printf("\n------------------------");
      printf("\n   Menu ");
      printf("\n------------------------");
      printf("\n 1- Enter_Student");
      printf("\n 2- Show_Student");
      printf("\n 3- END ");
      printf("\n------------------------");
      printf("\n What is your choice ? : ");
      printf("\n------------------------\n");
      scanf("%d", &g);
    } while (g <= 0 || g > 3);

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
        // printf(" en travaux ") ;
      }
    }

    if (g == 2) {
      show_n_student(s, N);
      system("pause");
      system("cls");
    }

  } while (g != 3);

  free(s);
}
