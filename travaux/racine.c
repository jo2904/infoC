#include <stdio.h>

int main(){
  int a, b, c;
  int discriminant;
  scanf("%d %d %d",&a,&b,&c);

  discriminant = (b*b)-(4*a*c);
  printf("%d\n", discriminant);

  if(discriminant>0){
    printf("2\n");
  }
  if(discriminant==0){
    printf("1\n");
  }
  if(discriminant<0){
    printf("0\n");
  }
}
