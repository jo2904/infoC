#include <stdio.h>
#include <math.h>

int main(){
  int a, b, c, discriminant;
  printf("Resolution de ax2+bx+c = 0\n");
  printf("a= ");
  scanf("%d", &a);
  printf("b= ");
  scanf("%d", &b);
  printf("c= ");
  scanf("%d", &c);
  
  discriminant = (b*b)-(4*a*c);
  
  if (discriminant>0){
    printf("x1= %f\n", (-b-sqrt(discriminant))/2*a);
    printf("x2= %f\n", (-b+sqrt(discriminant))/2*a);
  }
  if (discriminant==0)
    printf("x= %d\n", (-b/2));
  if (discriminant<0)
    printf("pas de solution\n");
    
 }
