#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void Deplacer(int *T1, int *T3){
  int temp = T1[0];
  for(int i = 1; i < 6; i++){
    T1[i-1] = T1[i];
  }
  T1[6] = -1;

  for(int i = 0; i < 6; i++){
    T3[i+1] = T3[i];
  }
  T3[0] = temp;
}

void Hanoi(int N, int *T1, int *T2, int *T3){
  if(1== N){
    Deplacer( T1, T3);
    return;
  }

  Hanoi(N-1, T1, T3, T2);
  Hanoi(1, T1, T2, T3);
  Hanoi(N-1, T2, T1, T3);
}

int main(){
  int T1[] = {5, 4, 3, 2, 1, -1, -1};
  int T2[] = {-1, -1, -1, -1, -1, -1, -1};
  int T3[] = {-1, -1, -1, -1, -1, -1, -1};
  Hanoi(5, T1, T2, T3);
}
