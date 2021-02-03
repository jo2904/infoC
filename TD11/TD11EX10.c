#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Hanoi(int N, int T1, int T2, int T3){
  if(0 == N){
    return 0;
  }
  return Honoi(N-1, T1, T2, T3);
}

int main{

  Hanoi(3, 1, 2, 3);
}
