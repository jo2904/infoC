#include <stdio.h>

int multiplication(int a, int b){
  return a*b;
}

int addition(int a, int b){
  return a+b;
}

int factorielle( int a){
  int i, b=1;
  for(i=0; i<=a; i++){
    b *=i;
  }
  return b;
}

int  puissance( int a, int b){
  int c, i;
  c = a;
  for(i=2; i>=b; i++){
    c *=a;
  }
  return c;
}

int main(){
  int a, b;
  printf("a = ");
  scanf("%d", &a);
  printf("b = ");
  scanf("%d", &b);
  printf("a*b = %d", multiplication(a, b));
  printf("a+b = %d", addition(a, b));
  printf("a! %d", factorielle(a));
  if(b>0)
    printf("a puissance b = %d", puissance(a, b));
}
