#include <stdio.h>

int fonc1(){
    srand(time(NULL));
    int i, tab[15];
    for(i=0; i<16; i++){
       tab[i] = rand()%2401+100;
    }
}

int fonc2(){
    int i, x, tab[15];
    for(i=0; i<16; i++){
       scanf("%d", &x);
       tab[i] = x;
    }
}
