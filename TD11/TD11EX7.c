#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int R(int n);

int S(int n){
  if(n == 1){
    return 200;
  }
  else {
    float a = 0.03, b = 0.0005;
    return S(n-1)*(1 + a - b * R(n-1));
  }
}

int R(int n){
  if(n == 1){
    return 50;
  }
  else {
    float c = 0.0005, k = 0.06;
    return R(n-1)*(1 + k + c * S(n-1));
  }
}

int main(){
  for(int i =1; i < 100; i++){
    printf("%d   %d\n", S(i), R(i));
  }
}
