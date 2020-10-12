#include <stdio.h>

int addition(int a, int b){
  return a+b;
}

int main(){
  int a, b;
  printf("a= ");
  scanf("%d", &a);
  printf("b= ");
  scanf("%d", &b);
  printf("a+b= %d\n", addition(a,b));
} 
