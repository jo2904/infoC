#include <stdio.h>

int main(){
  int a, b;
  printf("a= ");
  scanf("%d", &a);
  printf("b= ");
  scanf("%d", &b);
  a = a+b;
  b = a-b; 
  a = a-b;
  printf("\nInversion\n");
  printf("a= %d\n", a);
  printf("b= %d\n", b);
  
  return 0;
}
