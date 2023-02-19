//
// Created by Joachim Sonigo
//17/2/23
//

#include <stdio.h>
#include <stdlib.h>

void change_this(int *a,int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
    printf("\ninside switching them x=%d and y=%d",*a,*b);


}

int exo1() {
    int x,y;
    x=2;
    y=3;
    printf("\nBefore switching them x=%d and y=%d",x,y);
    change_this(&x,&y);
    printf("\nAfter the switch x= %d and y=%d",x,y);
}