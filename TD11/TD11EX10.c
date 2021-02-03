#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Hanoi(int N, int n, int *T1[], int *T2[], int *T3[]){
  if(n == N){
    return 0;
  }
  return Honoi(N, n+1, T1, T2, T3);
}

int main{
  int T2[] =  {3, 2, 1, -1, -1, -1, -1};
  int T2[] =  {-1, -1, -1, -1, -1, -1, -1};
  int T3[] =  {-1, -1, -1, -1, -1, -1, -1};

  Hanoi(3, 0, T1, T2, T3);
}
