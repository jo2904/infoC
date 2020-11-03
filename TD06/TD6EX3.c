#include <stdio.h>

int moyenne(int tab, int N){
    int i;
    float moyenne = 0;
    for(i=0; i<N+1; i++){
       moyenne = (moyenne + tab[i])/2;
    }
    return moyenne;
}

void afficheTab(int tab, int N){
    int i;
    for(i=0; i<N+1; i++){
       printf("%d", tab[i]);
    }
}
